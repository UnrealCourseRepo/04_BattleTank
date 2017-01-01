// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




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

	UE_LOG(LogTemp, Warning, TEXT("Player Tank found: %s"), *PlayerTank->GetName())
}