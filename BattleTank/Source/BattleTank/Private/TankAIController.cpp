// Do What The Fuck You Want To Public License

#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "../Public/TankAIController.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(AimingComponent))
	{
		UE_LOG(LogTemp, Error, TEXT("4c21: AIController can't find aiming component at BeginPlay"));
	}

	if (!ensure(PlayerTank))
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
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		AimingComponent->Fire();
	}
}
