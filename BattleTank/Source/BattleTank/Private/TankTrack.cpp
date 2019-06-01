// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "../Public/TankTrack.h"
#include "SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

}

void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForceWheel = ForceApplied / Wheels.Num();
	for (ASprungWheel* Wheel : Wheels) 
	{
		Wheel->AddDrivingForce(ForceApplied);
	}
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

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray <USceneComponent*> WheelSceneComponents;
	TArray <ASprungWheel*> ReturnArray;

	GetChildrenComponents(true, WheelSceneComponents);

	for (USceneComponent* Component : WheelSceneComponents) 
	{
		auto SpawnPoint = Cast<USpawnPoint>(Component);
		if (!SpawnPoint) {continue;}
		auto FoundSprungWheel = Cast<ASprungWheel>(SpawnPoint->GetSpawnedActor());
		if (!FoundSprungWheel) { continue; }
		ReturnArray.AddUnique(FoundSprungWheel);
	}
	return ReturnArray;
}
