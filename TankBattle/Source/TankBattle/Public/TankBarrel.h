// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankBarrel.generated.h"

// Holds Barrel's properties
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = "Collision")
class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Make all values conform to constraints set by MaxDegreesPerSecond
	void Elevate(float RelativeSpeed);	
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 40; //Circumstantial evidence that M1 Abrams can do full turret traverse in 9 seconds

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 30;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;

};
