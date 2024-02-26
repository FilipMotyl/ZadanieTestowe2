#include "BTDecorator_IsKeyTrue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsKeyTrue::UBTDecorator_IsKeyTrue()
{
	NodeName = TEXT("Is Key True");
	BlackboardKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UBTDecorator_IsKeyTrue, BlackboardKey));
}

bool UBTDecorator_IsKeyTrue::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	if (BlackboardComp)
	{
		return BlackboardComp->GetValueAsBool(BlackboardKey.SelectedKeyName);
	}
	return false;
}