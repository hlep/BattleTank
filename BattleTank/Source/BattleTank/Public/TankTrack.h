// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximusm driving force, and to apply forces to the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	UTankTrack();

	// Sets a throttle between -1 and 1
	UFUNCTION(BlueprintCallable)
	void SetThrottle(float Throttle);

	void DriveTrack();

	UFUNCTION(BlueprintCallable)
		void Brake();
	
	//Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000;

	UPROPERTY(EditDefaultsOnly)
		float TrackBreakForce = 4000000;

	UPROPERTY(BlueprintReadWrite)
	bool bIsReverse = false;

private:

	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, 
		FVector NormalImpulse, const FHitResult & Hit);

	float CurrentThrottle = 0;
};
