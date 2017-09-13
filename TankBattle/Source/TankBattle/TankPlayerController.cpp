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
	FVector HitLocation = GetHitLocation();
	UE_LOG(LogTemp, Warning, TEXT("Aiming at: %s"), *HitLocation.ToString());
	// Get raytraced location of crosshair point in the world
	// if it hits any world object
	// start moving tank barrel towards it
}

const float ATankPlayerController::GetSightRayHitLocation()
{
	FHitResult HitResult;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	bool IsHittingWorld = GetWorld()->LineTraceSingleByObjectType
	(
		HitResult,
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_Camera),
		TraceParameters
	);
	return HitResult.Distance;
}

FVector ATankPlayerController::GetReachLineStart()
{
	FVector PlayerViewpointLocation;
	FRotator PlayerViewpointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewpointLocation, OUT PlayerViewpointRotation);
	return PlayerViewpointLocation;
}

FVector ATankPlayerController::GetReachLineEnd()
{
	FVector PlayerViewpointLocation;
	FRotator PlayerViewpointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewpointLocation, OUT PlayerViewpointRotation);
	return PlayerViewpointLocation + PlayerViewpointRotation.Vector()*Reach;
}

FVector ATankPlayerController::GetHitLocation()
{
	FVector PlayerViewpointLocation;
	FRotator PlayerViewpointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewpointLocation, OUT PlayerViewpointRotation);
	return PlayerViewpointLocation + PlayerViewpointRotation.Vector()*GetSightRayHitLocation();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

