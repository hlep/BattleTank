// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank; // Forward declaration

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

private:
	
	ATank* ControlledTank = nullptr;
	ATank* PlayerTank = nullptr;

	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 3000; //TODO Check radius is in cm
};
