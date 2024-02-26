#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_DropBall.generated.h"

UCLASS()
class ZADANIETESTOWE2_API UBTTask_DropBall : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_DropBall();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};