// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlatform.h"

// Sets default values
AMyPlatform::AMyPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyPlatform::BeginPlay()
{
	Super::BeginPlay();
	startingLocation = GetActorLocation();
}

// Called every frame
void AMyPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move the platform
	// --- Get Actors location
	FVector myActorsLocation = GetActorLocation();

	// --- Add 1 to actors location x
	myActorsLocation = myActorsLocation + (movingVelocity * DeltaTime);

	// Get distance moved
	distanceMoved = FVector::Dist(myActorsLocation, startingLocation);

	// set Actors location
	SetActorLocation(myActorsLocation);
	// --- move actors location back if it has moved to much
	// --- reverse the actor location movement
	if (distanceMoved > moveDistance)
	{
		safeNormal = movingVelocity.GetSafeNormal();
		FVector movingDirection = movingVelocity.GetSafeNormal();
		startingLocation = startingLocation + movingDirection * moveDistance;
		movingVelocity = -movingVelocity;
		SetActorLocation(startingLocation);
	}
}
