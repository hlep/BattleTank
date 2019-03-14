// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "../Public/TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();

	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	// TODO clamp actual throttle value
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (bIsReverse) { ForceApplied = ForceApplied * -1; }
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTrack::Brake()
{
	//TODO Create a braking function
	/*
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto BreakSpeed = (TankRoot->ComponentVelocity) * FVector(-1);
	auto ForceLocation = GetComponentLocation();
	//FMath::Clamp<FVector>(BreakSpeed, FVector(0), FVector(TrackBreakForce));
	TankRoot->AddForceAtLocation(BreakSpeed, ForceLocation);
	UE_LOG(LogTemp, Warning, TEXT("Tank breaking"));
	*/
}
