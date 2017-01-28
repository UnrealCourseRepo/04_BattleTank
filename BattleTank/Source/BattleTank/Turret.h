// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent ))
class BATTLETANK_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Rotate(float DegreesPerSecond);

private:

	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesPerSecond = 10.0; 
	
	
};
