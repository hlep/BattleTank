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

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

private:

	APawn* PlayerTank = nullptr;

	UTankAimingComponent* AimingComponent = nullptr;

	// How close can the AI tank get
	float AcceptanceRadius = 1500;
};
