// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTanks();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI controller not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI is possessing: %s"), *ControlledTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTanks() const
{
	return Cast<ATank>(GetPawn());
}
