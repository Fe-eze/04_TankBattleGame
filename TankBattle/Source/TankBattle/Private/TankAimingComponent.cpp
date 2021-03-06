// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	// Calculate OutLaunchVelocity
	bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	)
		);
		if(bHaveAimSolution){
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		
			MoveBarrelTowards(AimDirection);

			MoveTurretTowards(AimDirection);

			//auto Time = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
		}
		else 
		{
			//auto Time = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("%f: No Aim solve found"), Time);
		}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// First, work out difference between barrelrotation and reticule(aimdirection)
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
{
	// First, work out difference between turret rotation and reticule(aimdirection)
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	Turret->Traverse(DeltaRotator.Yaw);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) 
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}