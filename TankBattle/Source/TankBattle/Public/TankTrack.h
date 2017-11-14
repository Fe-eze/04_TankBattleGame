// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * This class stores the properties of the tank tracks
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = "Collision")
class TANKBATTLE_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets a throttle value between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	UPROPERTY(EditDefaultsOnly)
	float MaxTrackDrivingForce = 536400; //'Sensible' default is based on a 60ton tank with 0-20mph(0-32.1869kmh) acceleration of 7.2sec ie 8.94m/s
};
