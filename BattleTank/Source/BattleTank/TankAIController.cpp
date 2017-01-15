// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"

#include "TankAIController.h"





void ATankAIController::Tick(float DeltaSeconds) 
{
	Super::Tick(DeltaSeconds);


	auto TargetTankLocation = GetPlayerTank()->GetActorLocation();

	GetControlledTank()->AimAt(TargetTankLocation);

	

}

AATank* ATankAIController::GetControlledTank()
{
	return Cast<AATank>(GetPawn());
}

AATank * ATankAIController::GetPlayerTank() const
{
	
	AATank* PlayerTank = Cast<AATank>(GetWorld()->
		GetFirstPlayerController()->GetPawn());
	if (!PlayerTank) { return nullptr; }

	return PlayerTank;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	AATank* ControlledAITank = nullptr;
	ControlledAITank = GetControlledTank();

	AATank* PlayerTank = GetPlayerTank();

	if (!ControlledAITank)
	{
		return;
	}

	
}