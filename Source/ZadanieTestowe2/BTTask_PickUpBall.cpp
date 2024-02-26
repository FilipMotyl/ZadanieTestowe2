#include "BTTask_PickUpBall.h"
#include "FM_AIController.h"
#include "FM_AICharacter.h"
#include "FM_Ball.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_PickUpBall::UBTTask_PickUpBall()
{
	NodeName = "Pick Up Ball";
}

EBTNodeResult::Type UBTTask_PickUpBall::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AFM_AIController* AIController = Cast<AFM_AIController>(OwnerComp.GetAIOwner());
	AFM_AICharacter* AICharacter = Cast<AFM_AICharacter>(AIController->GetPawn());
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	AFM_Ball* Ball = Cast<AFM_Ball>(BlackboardComp->GetValueAsObject("TargetObject"));

	if (AIController && AICharacter && BlackboardComp && Ball)
	{
		Ball->Destroy();
		AICharacter->PickUpBall();
		BlackboardComp->SetValueAsBool("HasBall", true);
		BlackboardComp->SetValueAsBool("ShouldPickUpBall", false);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}