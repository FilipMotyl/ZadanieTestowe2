#include "FM_Chest.h"
#include "FM_Character.h"
#include "FM_Ball.h"


AFM_Chest::AFM_Chest()
{
	PrimaryActorTick.bCanEverTick = true;

	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;

	ChestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest Mesh"));
	ChestMesh->SetupAttachment(RootComponent);

	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction Widget"));
	InteractionWidget->SetupAttachment(RootComponent);

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	SpawnPoint->SetupAttachment(RootComponent);
}

void AFM_Chest::BeginPlay()
{
	Super::BeginPlay();
	DynamicMaterial = UMaterialInstanceDynamic::Create(ChestMesh->GetMaterial(0), NULL);
	ChestMesh->SetMaterial(0, DynamicMaterial);
	HideInteractionWidget();
	Close();
}

void AFM_Chest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFM_Chest::ShowInteractionWidget()
{
	InteractionWidget->SetVisibility(true);
}

void AFM_Chest::HideInteractionWidget()
{
	InteractionWidget->SetVisibility(false);
}

void AFM_Chest::Interact(AFM_Character* InteractingCharacter)
{
	if (IsOpen)
	{
		Close();
	}
	else
	{
		Open();
	}
}

void AFM_Chest::Open()
{
	DynamicMaterial->SetVectorParameterValue(FName(TEXT("Color")), FLinearColor::Blue);
	IsOpen = true;

	FVector RandomDirection(FMath::FRandRange(-1.f, 1.f), FMath::FRandRange(-1.f, 1.f), 1);
	AFM_Ball* BallPtr = GetWorld()->SpawnActor<AFM_Ball>(BallClass, SpawnPoint->GetComponentLocation(), GetActorRotation());
	BallPtr->GetStaticMeshComponent()->AddImpulse(RandomDirection * 25000.f);
}

void AFM_Chest::Close()
{
	DynamicMaterial->SetVectorParameterValue(FName(TEXT("Color")), FLinearColor::Red);
	IsOpen = false;
}

