// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	//RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	//auto RawRotation = MaxDegreesPerSecond * RelativeSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawRotation = RelativeSpeed;
	
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: turret->rotate called at %f!"), Time, RawRotation);

	SetRelativeRotation(FRotator(0, RawRotation, 0));
}

