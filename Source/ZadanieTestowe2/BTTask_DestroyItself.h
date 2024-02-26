#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_DestroyItself.generated.h"

UCLASS()
class ZADANIETESTOWE2_API UBTTask_DestroyItself : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_DestroyItself();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};