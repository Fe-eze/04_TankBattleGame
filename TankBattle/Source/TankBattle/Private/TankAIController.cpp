// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Public/Tank.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto GetControlledTank = Cast<ATank>(GetPawn());	//Get Controlled tank
	auto GetPlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());	//then get player tank
	
	if (GetPlayerTank) {
		// TODO Move Toward Player

		// Aim Toward Player
		GetControlledTank->AimAt(GetPlayerTank->GetActorLocation());

		// Fire every frame
		GetControlledTank->Fire(); // TODO Limit firing rate ie dont fire every frame
	}
}