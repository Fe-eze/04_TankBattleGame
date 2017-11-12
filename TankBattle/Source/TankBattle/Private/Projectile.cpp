// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMotion = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement Comp"));
	ProjectileMotion->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float Speed)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Firiiiing!@!!, Speed: %f"), Time, Speed);

	ProjectileMotion->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMotion->Activate();
}
