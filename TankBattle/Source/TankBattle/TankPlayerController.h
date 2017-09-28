// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Core/Public/Math/Vector2D.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	// Makes tank barrel start rotating towards the position the crosshair is pointing towards.
	void AimTowardsCrosshair();

	ATank* GetControlledTank() const;

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.333333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void BeginPlay() override;
};
