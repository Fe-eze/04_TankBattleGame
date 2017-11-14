// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectBaseUtility.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//auto Name = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s set to a speed of %f"), *GetName(), Throttle);
	
	// TODO Clamp actual throttle values so player cannot overdrive

	auto ForceApplied = GetForwardVector()*Throttle;
	auto ForceLocation = GetComponentLocation()*MaxTrackDrivingForce;

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
