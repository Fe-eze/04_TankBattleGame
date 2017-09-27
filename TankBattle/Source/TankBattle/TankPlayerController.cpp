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
		UE_LOG(LogTemp, Warning, TEXT("Aiming at: %s"), *HitLocation.ToString());
		// TODO: start moving tank barrel towards it
	}
}

// Get raytraced location of crosshair point in the world, true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0f);
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

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

