// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel; 
class UTankTurret;

//Holds barrel properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

public:	

	void AimAt(FVector HitLocation, float LaunchSpeed);
	
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	void MoveBarrelTowards(FVector AimDirection);

private:

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

};
