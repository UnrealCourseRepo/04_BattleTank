// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




AATank* ATankAIController::GetControlledTank()
{
	return Cast<AATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	AATank* ControlledAITank = nullptr;
	ControlledAITank = GetControlledTank();

	if (!ControlledAITank)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing: %s"), *ControlledAITank->GetName())
}