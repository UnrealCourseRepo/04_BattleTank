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
	
private:
	AATank* GetControlledTank() const; // may return a null pointer

	void AimTowardsCrosshair();

	/// return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;


	
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;

	
};
