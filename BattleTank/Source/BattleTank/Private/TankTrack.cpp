// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "../Public/TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	// Calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	// Work-out the required acceleration this frame to correct
	auto CorrectionAcceleration = - SlippageSpeed / DeltaTime * GetRightVector();
	// Calculate and apply sideways force ( F = m * a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2; // Two tracks
	TankRoot->AddForce(CorrectionForce);

}

void UTankTrack::SetThrottle(float Throttle)
{
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
