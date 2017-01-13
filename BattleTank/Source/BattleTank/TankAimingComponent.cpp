// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );



	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) const
{
	UE_LOG(LogTemp, Warning, TEXT("Firing at... %f"), LaunchSpeed);
	
	if (!Barrel) { return; }
	
	FVector OutLaunchVelocity = FVector(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("ProjectileEnd"));
	float CollisionRadius = 100.f;
	FCollisionResponseParams Params(ECollisionResponse::ECR_Block);
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Emplace(GetOwner());

	
	
	UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		CollisionRadius,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		Params,
		ActorsToIgnore,
		true
	);

	auto AimDirection = OutLaunchVelocity.GetSafeNormal();

	UE_LOG(LogTemp, Warning, TEXT("Suggested Launch Velocity: %s"), *OutLaunchVelocity.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *AimDirection.ToString());

	return;
}

