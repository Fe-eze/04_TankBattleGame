// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

// Hold's turret properties
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = "Collision")
class TANKBATTLE_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Make all values conform to constraints set by MaxDegreesPerSecond
	void Traverse(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 40;
	
	
};
