#include "FM_PlayerController.h"
#include "FM_W_BallCounter.h"

void AFM_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (BallCounterWidgetClass)
	{
		BallCounterWidget = CreateWidget<UFM_W_BallCounter>(this, BallCounterWidgetClass);
		if (BallCounterWidget)
		{
			BallCounterWidget->AddToViewport();
		}
	}
}