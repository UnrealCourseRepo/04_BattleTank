// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ATank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	AATank* GetControlledTank();

	AATank* GetPlayerTank() const;  // may return a null pointer
	
	
};
