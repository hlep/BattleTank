// Do What The Fuck You Want To Public License


#include "SprungWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("PhysicsConstraint"));
	SetRootComponent(PhysicsConstraint);

	Mass = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mass"));
	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wheel"));

	Mass->SetupAttachment(PhysicsConstraint);
	Wheel->SetupAttachment(PhysicsConstraint);
	Mass->SetSimulatePhysics(true);
	Wheel->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetAttachParentActor()) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Null"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("NULL"));
	}
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

