// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond) 
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate called at: %f"), DegreesPerSecond);
	// Move barrel towards aimsolution as defined by barrelmovespeed (this frame)
	// if barrelrotation = reticule position (aimdirection)
	//Stop move
}

