// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "ATank.h"



AATank* ATankPlayerController::GetControlledTank() const
{
	AATank* ControlledTank = nullptr;
	
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) {return ControlledTank;}

	ControlledTank = Cast<AATank>(ControlledPawn);
	if (!ControlledTank) { return ControlledTank; }
		
	return ControlledTank;
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;}
		
	FVector HitLocation; // OUT parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		

		GetControlledTank()->AimAt(HitLocation);
		
	}

	
	return;
}





void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	

	AATank* ControlledTank = GetControlledTank();
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AimTowardsCrosshair();

}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{

	// do a ray cast from the crosshair dot
	// find the dot

	int32 ViewPortSizeX = 0;
	int32 ViewPortSizeY = 0;

	GetWorld()->GetFirstPlayerController()->GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	// crosshair is at X/2 and Y/3
	auto ScreenLocation = FVector2D((CrossHairXLocation*ViewPortSizeX),
		(CrossHairYLocation*ViewPortSizeY));
	//UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *ScreenLocation.ToString());

	// deproject crosshair to world
	auto WorldLocation = FVector(1.0f, 1.0f, 1.0f);
	auto WorldDirection = FVector(1.0f, 1.0f, 1.0f);

	if (GetWorld()->GetFirstPlayerController()->DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y, WorldLocation,
		WorldDirection))
	{
		/*UE_LOG(LogTemp, Warning, TEXT("World Location: %s  and WorldDirection: %s"),
		*WorldLocation.ToString(), *WorldDirection.ToString());*/

		/// do the line trace
		FHitResult HitResult;
		auto StartLocation = PlayerCameraManager->GetCameraLocation();
		auto LineTraceEnd = StartLocation + (WorldDirection * AimDistance);
		if (GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation,
			LineTraceEnd, ECollisionChannel::ECC_Visibility))
		{
			HitLocation = HitResult.Location;
			//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
			return true;
		}
		HitLocation = FVector(0);
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		return false;


	}


	return false;
}