// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



AATank* ATankPlayerController::GetControlledTank() const
{
	AATank* ControlledTank = nullptr;
	
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) {return ControlledTank;}

	ControlledTank = Cast<AATank>(ControlledPawn);
	if (!ControlledTank) { return ControlledTank; }
		
	return ControlledTank;
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;}


	
	return;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	

	AATank* ControlledTank = GetControlledTank();
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AimTowardsCrosshair();

}
