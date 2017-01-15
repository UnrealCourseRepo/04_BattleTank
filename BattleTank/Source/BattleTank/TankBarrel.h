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
	
	void Elevate(float DegreesPerSecond) const;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20;  // sensible default value

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesElevation = 75; // sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegreesElevation = 5;

	
	
};
