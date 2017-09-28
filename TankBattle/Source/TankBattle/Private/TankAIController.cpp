// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI controller cannot see player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I see you!!! @ %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TODO Move Toward Player

	// Aim Toward Player
	GetControlledTanks()->AimAt(GetPlayerTank()->GetActorLocation());

	// Fire if ready
}


ATank* ATankAIController::GetControlledTanks() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}