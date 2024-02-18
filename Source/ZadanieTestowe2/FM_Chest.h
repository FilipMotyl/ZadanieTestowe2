#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FM_InteractionInterface.h"
#include <Components/WidgetComponent.h>
#include "FM_Chest.generated.h"


UCLASS()
class ZADANIETESTOWE2_API AFM_Chest : public AActor, public IFM_InteractionInterface
{
	GENERATED_BODY()
	
public:	
	AFM_Chest();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void ShowInteractionWidget() override;

	virtual void HideInteractionWidget() override;

	virtual void Interact(class AFM_Character* InteractingCharacter) override;

private:
	void Open();

	void Close();

	UPROPERTY(EditAnywhere)
	USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ChestMesh;

	UPROPERTY(EditAnywhere)
	UWidgetComponent* InteractionWidget;

	UPROPERTY(EditAnywhere)
	USceneComponent* SpawnPoint;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AFM_Ball> BallClass;

	UMaterialInstanceDynamic* DynamicMaterial;

	bool IsOpen = false;
};