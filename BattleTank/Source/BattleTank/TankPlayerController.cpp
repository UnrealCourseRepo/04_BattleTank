// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



AATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<AATank>(GetPawn());
}
