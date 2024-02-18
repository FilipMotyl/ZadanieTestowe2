#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "FM_W_BallCounter.generated.h"

UCLASS()
class ZADANIETESTOWE2_API UFM_W_BallCounter : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
};