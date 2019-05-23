// Do What The Fuck You Want To Public License

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward declaration
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	void Tick(float DeltaTime) override;

protected:

	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 2000;

private:

	void BeginPlay() override;

	void SetPawn(APawn* InPawn) override;

	APawn* PlayerTank = nullptr;

	UTankAimingComponent* AimingComponent = nullptr;

	UFUNCTION()
	void OnTankDeath();

};
