#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_Blackboard.h"
#include "BTDecorator_IsKeyTrue.generated.h"

UCLASS()
class ZADANIETESTOWE2_API UBTDecorator_IsKeyTrue : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTDecorator_IsKeyTrue();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};