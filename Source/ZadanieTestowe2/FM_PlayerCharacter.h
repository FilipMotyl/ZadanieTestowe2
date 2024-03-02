// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Components/SphereComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "Delegates/Delegate.h"
#include "FM_InteractionInterface.h"
#include "CoreMinimal.h"
#include "FM_Character.h"
#include "FM_PlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBallThrown, class AFM_Ball*, BallThrown);

UCLASS()
class ZADANIETESTOWE2_API AFM_PlayerCharacter : public AFM_Character
{
	GENERATED_BODY()
	
public:
	AFM_PlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	FOnBallThrown OnBallThrown;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void TurnRate(float AxisValue);

	void Interact();
	void Throw();

	UPROPERTY(EditAnywhere)
	float RotationRate = 25;

	UPROPERTY(EditAnywhere)
	float ThrowPower = 75000;

	bool bShouldProjectTrajectory;

	UPROPERTY(EditAnywhere)
	USphereComponent* InteractionSphere;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	IFM_InteractionInterface* TargetInteractible = nullptr;
};