#include "FM_AIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "FM_PlayerCharacter.h"
#include "FM_Ball.h"

void AFM_AIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		Blackboard->SetValueAsObject(TEXT("PlayerObject"), PlayerPawn);
		Blackboard->SetValueAsBool(TEXT("HasBall"), false);
	}


	AFM_PlayerCharacter* player = Cast<AFM_PlayerCharacter>(PlayerPawn);
	if (player)
	{
		player->OnBallThrown.AddDynamic(this, &AFM_AIController::HandleBallThrown);
	}
}

void AFM_AIController::HandleBallThrown(AFM_Ball* BallThrown)
{
	if (Blackboard->GetValueAsObject(TEXT("TargetObject")) == nullptr) 
	{
		Blackboard->SetValueAsObject(TEXT("TargetObject"), BallThrown);
	}
}