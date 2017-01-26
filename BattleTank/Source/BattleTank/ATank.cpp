// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "ATank.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"


void AATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);		
	Barrel = BarrelToSet;
	
}

void AATank::SetTurretReference(UTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void AATank::Fire()
{
	if (!Barrel) 
	{ return; }	
	

	/// this compiles but DOES NOT WORK
	GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("ProjectileEnd")),
		Barrel->GetSocketRotation(FName("ProjectileEnd"))
		);
	
}

// Sets default values
AATank::AATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void AATank::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called to bind functionality to input
void AATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AATank::AimAt(FVector HitLocation) const
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

	
	return;
}