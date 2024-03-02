#include "FM_PlayerCharacter.h"
#include "FM_Ball.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <DrawDebugHelpers.h>

AFM_PlayerCharacter::AFM_PlayerCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Interaction Sphere"));
	InteractionSphere->SetupAttachment(RootComponent);
}

void AFM_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFM_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<AActor*> OverlappingActors;
	InteractionSphere->GetOverlappingActors(OverlappingActors);

	if (OverlappingActors.Num() == 0)
	{
		if (TargetInteractible)
		{
			TargetInteractible->HideInteractionWidget();
			TargetInteractible = nullptr;
		}
		return;
	}

	AActor* ClosestActor = OverlappingActors[0];
	for (AActor* CurrentActor : OverlappingActors)
	{
		if (GetDistanceTo(CurrentActor) < GetDistanceTo(ClosestActor))
		{
			ClosestActor = CurrentActor;
		}
	}

	if (TargetInteractible)
	{
		TargetInteractible->HideInteractionWidget();
	}

	TargetInteractible = Cast<IFM_InteractionInterface>(ClosestActor);

	if (TargetInteractible)
	{
		TargetInteractible->ShowInteractionWidget();
	}
}

void AFM_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AFM_PlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AFM_PlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AFM_PlayerCharacter::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &AFM_PlayerCharacter::TurnRate);

	PlayerInputComponent->BindAction(TEXT("Interact"), EInputEvent::IE_Pressed, this, &AFM_PlayerCharacter::Interact);
	PlayerInputComponent->BindAction(TEXT("Throw"), EInputEvent::IE_Pressed, this, &AFM_PlayerCharacter::Throw);
}

void AFM_PlayerCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AFM_PlayerCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AFM_PlayerCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AFM_PlayerCharacter::TurnRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AFM_PlayerCharacter::Interact()
{
	if (TargetInteractible)
	{
		TargetInteractible->Interact(this);
	}
}

void AFM_PlayerCharacter::Throw()
{
	if (BallCount <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Sorry, no balls."));
	}
	else
	{
		AFM_Ball* BallPtr = GetWorld()->SpawnActor<AFM_Ball>(BallClass, SpawnPoint->GetComponentLocation(), Camera->GetComponentRotation());
		BallPtr->GetStaticMeshComponent()->AddImpulse(Camera->GetForwardVector() * ThrowPower);
		if (--BallCount == 0)
		{
			HeldBallMesh->SetVisibility(false);
			OnBallThrown.Broadcast(BallPtr);
		}
	}
}