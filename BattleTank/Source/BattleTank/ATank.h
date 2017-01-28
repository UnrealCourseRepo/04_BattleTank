// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "ATank.generated.h"

class UTankBarrel;
class UTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API AATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation) const;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Actions)
		void Fire();

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000.0f;

	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	


protected:
	UTankAimingComponent* TankAimingComponent = nullptr;


private:

// Sets default values for this pawn's properties
	AATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Classes)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	// need this to locate spawned projectiles
	UTankBarrel* Barrel = nullptr;
		
};
