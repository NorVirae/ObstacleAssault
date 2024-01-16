// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlatform.generated.h"

UCLASS()
class OBSTACEASSAULT_API AMyPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	float GetDistanceMoved(FVector myActorsLocation);
	bool ShouldPlatformReturn(FVector myActorsLocation);

		// velocity
	UPROPERTY(EditAnywhere, category = "Moving Platorm")
	FVector movingVelocity = FVector(0, 40, 0);

	// velocity
	UPROPERTY(VisibleAnywhere, category = "Moving Platorm")
	float distanceMoved = 0;

	UPROPERTY(EditAnywhere, category = "Moving Platorm")
	float moveDistance = 1100;

	UPROPERTY(VisibleAnywhere, category = "Moving Platorm")
	FVector startingLocation;

	UPROPERTY(VisibleAnywhere, category = "Moving Platorm")
	FVector safeNormal;
};
