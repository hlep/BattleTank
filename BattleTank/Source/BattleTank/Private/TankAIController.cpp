// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "../Public/TankAIController.h"
#include "GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();
	if (ControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController didn't find a tank!")); //log an error
	}

	if (PlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerTank not found")); //log an error
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found your tank: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerTank);
}
