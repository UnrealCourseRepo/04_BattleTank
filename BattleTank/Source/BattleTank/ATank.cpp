// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "ATank.h"


// Sets default values
AATank::AATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AATank::AimAt(FVector HitLocation) const
{
	UE_LOG(LogTemp, Warning, TEXT("AimAt(HitLocation) called...."));
	auto OurTankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *OurTankName, *HitLocation.ToString() )
	
	return;
}