// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "../Public/TankAIController.h"
#include "GameFramework/Actor.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = Cast<ATank>(GetPawn());;
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("4c21: AIController didn't find a tank!")); //log an error
	}

	if (PlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("4c21: PlayerTank not found")); //log an error
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ensure(PlayerTank)) 
	{
		//Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); // TODO limit firing rate
	}
}
