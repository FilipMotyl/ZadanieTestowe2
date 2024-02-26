#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_PickUpBall.generated.h"

UCLASS()
class ZADANIETESTOWE2_API UBTTask_PickUpBall : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_PickUpBall();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
