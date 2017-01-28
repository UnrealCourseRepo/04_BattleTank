// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "ATank.h"
#include "TankAIController.h"





void ATankAIController::Tick(float DeltaSeconds) 
{
	Super::Tick(DeltaSeconds);

	auto TargetTank = Cast<AATank>(GetWorld()->
		GetFirstPlayerController()->GetPawn());
	
	if (!TargetTank) { return; }	
	auto TargetTankLocation = TargetTank->GetActorLocation();
	
	auto ControlledTank = Cast<AATank>(GetPawn());

	if (!ControlledTank) { return; }
	ControlledTank->AimAt(TargetTankLocation);

	ControlledTank->Fire();

}



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	
	
}