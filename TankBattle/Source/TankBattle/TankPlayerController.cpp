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
		//UE_LOG(LogTemp, Warning, TEXT("Aim Reticule Look Direction: %s"), *HitLocation.ToString());
		// TODO: start moving tank barrel towards it
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
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
	}
	// Linetrace along look direction and see what we hit (up to a maximum range)
	return true;
	//FHitResult HitResult;
	//FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	//bool IsHittingWorld = GetWorld()->LineTraceSingleByObjectType
	//(
	//	HitResult,
	//	GetReachLineStart(),
	//	GetReachLineEnd(),
	//	FCollisionObjectQueryParams(ECollisionChannel::ECC_Camera),
	//	TraceParameters
	//);
	//return HitResult.Distance;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const 
{
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

