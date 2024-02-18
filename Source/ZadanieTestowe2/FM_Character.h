// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Components/SphereComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "FM_InteractionInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FM_Character.generated.h"

UCLASS()
class ZADANIETESTOWE2_API AFM_Character : public ACharacter
{
	GENERATED_BODY()

public:
	AFM_Character();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PickUpBall();

	UPROPERTY(BlueprintReadOnly)
	int32 BallCount = 0;

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

	UPROPERTY(EditAnywhere)
	USphereComponent* InteractionSphere;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* HeldBallMesh;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AFM_Ball> BallClass;

	UPROPERTY(EditAnywhere)
	USceneComponent* SpawnPoint;

	IFM_InteractionInterface* TargetInteractible = nullptr;
};