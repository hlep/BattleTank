// Do What The Fuck You Want To Public License

#include "Tank.h"
#include "../Public/Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FMath::RoundToInt(DamageAmount); // For better use in UI and comparison to 0

	DamagePoints = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	UE_LOG(LogTemp, Warning, TEXT("got damaged for: %i"), DamagePoints);
	CurrentHealth -= DamagePoints;
	return DamagePoints;
}

