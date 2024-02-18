#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FM_PlayerController.generated.h"

UCLASS()
class ZADANIETESTOWE2_API AFM_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<class UFM_W_BallCounter> BallCounterWidgetClass;

	UFM_W_BallCounter* BallCounterWidget;
};