// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FM_AIController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ZADANIETESTOWE2_API AFM_AIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	AActor* TargetActor;

private:
	APawn* PlayerPawn;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

	UFUNCTION()
	void HandleBallThrown(AFM_Ball* BallThrown);
};
