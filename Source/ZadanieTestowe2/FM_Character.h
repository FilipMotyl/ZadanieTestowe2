#pragma once
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

	virtual void PickUpBall();
	
	UPROPERTY(BlueprintReadOnly)
	int32 BallCount = 0;

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* HeldBallMesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AFM_Ball> BallClass;

	UPROPERTY(EditAnywhere)
	USceneComponent* SpawnPoint;
};