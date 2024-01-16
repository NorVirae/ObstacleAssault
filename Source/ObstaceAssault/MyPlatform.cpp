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
	FString actorName = GetName();
	UE_LOG(LogTemp, Display, TEXT("Actor: %s"), *actorName);
}

// Called every frame
void AMyPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move the platform
	// --- Get Actors location

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMyPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(rotationVelocity * DeltaTime);
	// UE_LOG(LogTemp, Display, TEXT("Rotation velocity X: %f, Y: %f, Z: %f"), rotationVelocity.X, rotationVelocity, rotationVelocity.Z);
}

void AMyPlatform::MovePlatform(float DeltaTime)
{

	FVector myActorsLocation = GetActorLocation();

	// --- reverse the actor location movement
	if (ShouldPlatformReturn(myActorsLocation))
	{
		safeNormal = movingVelocity.GetSafeNormal();
		FVector movingDirection = movingVelocity.GetSafeNormal();
		startingLocation = startingLocation + movingDirection * moveDistance;
		movingVelocity = -movingVelocity;
		SetActorLocation(startingLocation);
	}
	else
	{
		// --- Add 1 to actors location x
		myActorsLocation = myActorsLocation + (movingVelocity * DeltaTime);
		// set Actors location
		SetActorLocation(myActorsLocation);
	}
}

bool AMyPlatform::ShouldPlatformReturn(FVector myActorsLocation) const
{
	return GetDistanceMoved(myActorsLocation) > moveDistance;
}

float AMyPlatform::GetDistanceMoved(FVector myActorsLocation) const
{
	float distanceMoved = FVector::Dist(myActorsLocation, startingLocation);
	return distanceMoved;
}