// Do What The Fuck You Want To Public License

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent)) { FoundAimingComponent(AimingComponent); }
	else
	{
		UE_LOG(LogTemp, Error, TEXT("4c21: PlayerController can't find aiming component at BeginPlay"));
	}

}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//Subscribe local method to the tank's death event
		PossessedTank->OnTankDeath.AddUniqueDynamic(this, &ATankPlayerController::OnTankDeath);
	}

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; }

	FVector HitLocation; //out parameter

	if (GetSightRayHitLocation(HitLocation)) //tells controlled tank to aim at the point if it hits the landscape
	{
		AimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation;
	ScreenLocation.X = ViewportSizeX * CrossHairXLocation;
	ScreenLocation.Y = ViewportSizeY * CrossHairYLocation;
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//Line-trace along LookDirection
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto CameraLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = CameraLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, 
		CameraLocation,
		EndLocation, 
		ECC_Camera))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}


void ATankPlayerController::OnTankDeath()
{
	StartSpectatingOnly();
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation; //not needed
	return DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
}



