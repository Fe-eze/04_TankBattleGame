// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	ATank* GetControlledTank() const;
	
	FVector GetReachLineStart();
	FVector GetReachLineEnd();
	FVector GetHitLocation();

	float Reach = 200000.f;

	const float GetSightRayHitLocation();

public:
	virtual void Tick(float DeltaTime) override;
	
	// Makes tank barrel start rotating towards the position the crosshair is pointing towards.
	void AimTowardsCrosshair();
};
