#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FM_InteractionInterface.generated.h"

UINTERFACE(MinimalAPI)
class UFM_InteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class ZADANIETESTOWE2_API IFM_InteractionInterface
{
	GENERATED_BODY()

public:
	virtual void Interact(class AFM_Character* InteractingCharacter);
	virtual void ShowInteractionWidget();
	virtual void HideInteractionWidget();
};