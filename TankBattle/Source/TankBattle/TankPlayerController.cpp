// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player controller not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s is current player tank"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) // Has a side-effect in that it's going to linetrace
	{
		// TODO: start moving tank barrel towards it
		GetControlledTank()->AimAt(HitLocation);
	}
}

// Get raytraced location of crosshair point in the world, true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation2 = FVector2D(ViewportSizeX* CrosshairXLocation, ViewportSizeY* CrosshairYLocation);

	// Deproject crosshair screen position to world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation2, LookDirection)) {
		// Linetrace along look direction and see what we hit (up to a maximum range)
		GetLookVectorHitLocation(OutHitLocation, LookDirection);

		// Log out hit direction info
		//UE_LOG(LogTemp, Warning, TEXT("Aim Reticule Look Direction: %s"), *OutHitLocation.ToString());
	}
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const 
{
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& OutHitLocation, FVector LookDirection) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();

	if (GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		StartLocation + LookDirection*LineTraceRange, // Trace End Location
		ECollisionChannel::ECC_Visibility
	))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false; // Line Trace failure
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

