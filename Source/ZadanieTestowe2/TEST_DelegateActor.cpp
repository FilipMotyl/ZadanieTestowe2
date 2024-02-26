// Fill out your copyright notice in the Description page of Project Settings.


#include "TEST_DelegateActor.h"

// Sets default values
ATEST_DelegateActor::ATEST_DelegateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATEST_DelegateActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATEST_DelegateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

