#include "FM_Character.h"
#include "FM_Ball.h"

AFM_Character::AFM_Character()
{
	PrimaryActorTick.bCanEverTick = true;

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
}

void AFM_Character::PickUpBall()
{
	if (BallCount <= 0)
	{
		HeldBallMesh->SetVisibility(true);
	}
	BallCount++;
}