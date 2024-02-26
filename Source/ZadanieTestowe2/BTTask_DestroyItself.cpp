#include "BTTask_DestroyItself.h"
#include "AIController.h"

UBTTask_DestroyItself::UBTTask_DestroyItself()
{
	NodeName = TEXT("Destroy Itself");
}

EBTNodeResult::Type UBTTask_DestroyItself::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (OwnerComp.GetAIOwner() && OwnerComp.GetAIOwner()->GetPawn())
	{
		OwnerComp.GetAIOwner()->GetPawn()->Destroy();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
