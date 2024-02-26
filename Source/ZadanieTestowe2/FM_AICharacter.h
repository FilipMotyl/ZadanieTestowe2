#pragma once

#include "CoreMinimal.h"
#include "FM_Character.h"
#include "FM_AICharacter.generated.h"

UCLASS()
class ZADANIETESTOWE2_API AFM_AICharacter : public AFM_Character
{
	GENERATED_BODY()

public:
	void DropBall();
};