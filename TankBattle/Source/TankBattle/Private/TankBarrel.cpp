// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle/Public/TankBarrel.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed) 
{
	auto RelSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
	auto ElevationChange = RelSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds; // deltatimesec makes it frame independent
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	
	// Move barrel towards aimsolution as defined by barrelmovespeed (this frame)
	// if barrelrotation = reticule position (aimdirection)
	//Stop move
}

