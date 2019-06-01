// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
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

	void DriveTrack(float CurrentThrottle);

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

	TArray<ASprungWheel*> GetWheels() const;

	virtual void BeginPlay() override;

};
