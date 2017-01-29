// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::IntendForwardMove(float Throw)
{
	if (!LeftTankTrack || !RightTankTrack) { return; }
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(Throw);
}

void UTankMovementComponent::SetReferences(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{	
	LeftTankTrack = LeftTrackToSet;
	RightTankTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTankTrack || !RightTankTrack) { return; }
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(-Throw);
}

