// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);	
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond *
		GetWorld()->DeltaTimeSeconds;
	auto Elevation = RelativeRotation.Pitch + ElevationChange;

	Elevation = FMath::Clamp<float>(Elevation, MinDegreesElevation,
		MaxDegreesElevation);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
	return;
}

