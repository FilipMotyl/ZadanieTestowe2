#include "FM_Ball.h"
#include "FM_Character.h"


AFM_Ball::AFM_Ball()
{
	PrimaryActorTick.bCanEverTick = true;

	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;
	
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere Mesh"));
	BallMesh->SetupAttachment(RootComponent);

	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction Widget"));
	InteractionWidget->SetupAttachment(BallMesh);
}

void AFM_Ball::BeginPlay()
{
	Super::BeginPlay();
	HideInteractionWidget();
}

void AFM_Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFM_Ball::ShowInteractionWidget()
{
	InteractionWidget->SetVisibility(true);
}

void AFM_Ball::HideInteractionWidget()
{
	InteractionWidget->SetVisibility(false);
}

void AFM_Ball::Interact(AFM_Character* InteractingCharacter)
{
	InteractingCharacter->PickUpBall();
	this->Destroy();
}

UStaticMeshComponent* AFM_Ball::GetStaticMeshComponent()
{
	return BallMesh;
}