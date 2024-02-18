#include "FM_Character.h"
#include "FM_Ball.h"
#include <Components/BoxComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>

AFM_Character::AFM_Character()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Interaction Sphere"));
	InteractionSphere->SetupAttachment(RootComponent);

	HeldBallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	HeldBallMesh->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("BallSocket"));

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	SpawnPoint->SetupAttachment(RootComponent);
}

void AFM_Character::BeginPlay()
{
	Super::BeginPlay();
	HeldBallMesh->SetVisibility(false);
}

void AFM_Character::Tick(float DeltaTime)
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

void AFM_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AFM_Character::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AFM_Character::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AFM_Character::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &AFM_Character::TurnRate);

	PlayerInputComponent->BindAction(TEXT("Interact"), EInputEvent::IE_Pressed, this, &AFM_Character::Interact);
	PlayerInputComponent->BindAction(TEXT("Throw"), EInputEvent::IE_Pressed, this, &AFM_Character::Throw);
}

void AFM_Character::PickUpBall()
{

	if (BallCount <= 0)
	{
		HeldBallMesh->SetVisibility(true);
	}

	BallCount++;
}

void AFM_Character::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AFM_Character::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AFM_Character::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AFM_Character::TurnRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AFM_Character::Interact()
{
	if (TargetInteractible)
	{
		TargetInteractible->Interact(this);
	}
}

void AFM_Character::Throw()
{
	if (BallCount <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Sorry, no balls."));
	}
	else
	{
		AFM_Ball* BallPtr = GetWorld()->SpawnActor<AFM_Ball>(BallClass, SpawnPoint->GetComponentLocation(), GetActorRotation());
		BallPtr->GetStaticMeshComponent()->AddImpulse(Camera->GetForwardVector() * ThrowPower);
		if (--BallCount == 0)
		{
			HeldBallMesh->SetVisibility(false);
		}
	}
}