#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include <Components/WidgetComponent.h>
#include "FM_InteractionInterface.h"
#include "FM_Ball.generated.h"

UCLASS()
class ZADANIETESTOWE2_API AFM_Ball : public AActor, public IFM_InteractionInterface
{
	GENERATED_BODY()
	
public:	
	AFM_Ball();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void ShowInteractionWidget() override;

	virtual void HideInteractionWidget() override;

	virtual void Interact(class AFM_Character* InteractingCharacter) override;

	UStaticMeshComponent* GetStaticMeshComponent();

private:
	UPROPERTY(EditAnywhere)
	USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BallMesh;

	UPROPERTY(EditAnywhere)
	UWidgetComponent* InteractionWidget;

	UPROPERTY(EditDefaultsOnly)
	UNiagaraComponent* TrailParticle;
};