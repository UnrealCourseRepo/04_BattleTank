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



void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
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
				false,
				0,
				0,
				ESuggestProjVelocityTraceOption::DoNotTrace
			);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		
		MoveBarrel(AimDirection);

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f:  Aim solve found."), Time)

			
	}	

	else {
		auto Time = GetWorld()->GetTimeSeconds();
		auto AimDirection = OutLaunchVelocity.GetSafeNormal().ToString();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solve not found."), Time);
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