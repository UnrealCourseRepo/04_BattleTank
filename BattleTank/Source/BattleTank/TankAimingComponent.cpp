// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"



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



void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) const
{
	
	
	if (!Barrel) { return; }
	
	FVector OutLaunchVelocity = FVector(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("ProjectileEnd"));
	float CollisionRadius = 0.001f;
	FCollisionResponseParams Params(ECollisionResponse::ECR_Block);
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Emplace(GetOwner());

	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
			(
				this,
				OutLaunchVelocity,
				StartLocation,
				HitLocation,
				LaunchSpeed,
				ESuggestProjVelocityTraceOption::DoNotTrace
			);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		
		MoveBarrel(AimDirection);

			
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

	UE_LOG(LogTemp, Warning, TEXT("DeltaRotator: %s"), *DeltaRotator.ToString());

	Barrel->Elevate(5);
}