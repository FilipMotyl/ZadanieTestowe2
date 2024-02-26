#include "BTTask_DropBall.h"
#include "FM_AIController.h"
#include "FM_AICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_DropBall::UBTTask_DropBall()
{
	NodeName = "Drop Ball";
}

EBTNodeResult::Type UBTTask_DropBall::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AFM_AIController* AIController = Cast<AFM_AIController>(OwnerComp.GetAIOwner());
	AFM_AICharacter* AICharacter = Cast<AFM_AICharacter>(AIController->GetPawn());
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (AIController && AICharacter && BlackboardComp)
	{
		AICharacter->DropBall();
		BlackboardComp->SetValueAsBool("HasBall", false);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
