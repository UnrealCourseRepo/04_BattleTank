// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	
	// +1 is max upward movement; -1 is max downward movement
	void Elevate(float RelativeSpeed);

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 5;  // sensible default value

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesElevation = 40; // sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegreesElevation = 0;

	
	
};
