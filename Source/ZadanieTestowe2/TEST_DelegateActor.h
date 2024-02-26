// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/Delegate.h"
#include "TEST_DelegateActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKaramba, AActor*, ActorName);

UCLASS()
class ZADANIETESTOWE2_API ATEST_DelegateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATEST_DelegateActor();

	UPROPERTY()
	FKaramba TestDelegate5;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
