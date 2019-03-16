// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"


void UTankMovementComponent::IntendMoveForward(float Throw)
{

	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Intend move forward throw: %f"), *Name, Throw);
}

