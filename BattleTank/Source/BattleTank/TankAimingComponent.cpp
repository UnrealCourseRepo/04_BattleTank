// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Turret.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTurret* TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	
	
	if (!Barrel) { return; }
	
	FVector OutLaunchVelocity = FVector(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("ProjectileEnd"));
	FVector EndLocation = StartLocation + (HitLocation - StartLocation) * 0.75f;
	FCollisionResponseParams Params(ECollisionResponse::ECR_Block);
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Emplace(GetOwner());

	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
			(
				this,
				OutLaunchVelocity,
				StartLocation,
				EndLocation,
				LaunchSpeed,
				false,
				0,
				0,
				ESuggestProjVelocityTraceOption::TraceFullPath
			);

	auto ZeroVector = FVector(0);

	// test for aim solve AND non-zero hitlocation
	if (bHaveAimSolution && (HitLocation.X != ZeroVector.X)) //TODO prevents hitting anything at X=0
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		
		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);

		auto Time = GetWorld()->GetTimeSeconds();
		auto Tank = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%f:  Aim solve found. (%s, reporing"), Time, *Tank)

			
	}	

	else 
	{
		auto Time = GetWorld()->GetTimeSeconds();
		auto Tank = GetOwner()->GetName();
		auto AimDirection = OutLaunchVelocity.GetSafeNormal().ToString();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solve not found. (%s reporting"), Time, *Tank);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *AimDirection);
	}

	

	return;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) const
{
	
	// Set the barrel mesh's rotation to that obtained
	if(!Barrel)
	{
		return;
	}

	//  TODO:  Barrel->SetRelativeRotation(AimRotator.Pitch);
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;

	
	auto Time = GetWorld()->GetTimeSeconds();

	
	

	Barrel->Elevate(DeltaRotator.Pitch);
	
	
}

void UTankAimingComponent::MoveTurret(FVector AimDirection)
{
	if (!Turret) 
	{
		return;
	}

	auto TurretRotation = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotation;

	Turret->Rotate(DeltaRotator.Yaw);


	
	return;
}
