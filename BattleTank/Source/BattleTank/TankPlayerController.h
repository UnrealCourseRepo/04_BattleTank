// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ATank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AATank* GetControlledTank() const; // may return a null pointer
	
	virtual void BeginPlay() override;
	
};
