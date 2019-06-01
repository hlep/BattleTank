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

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wheel"));

	Wheel->SetupAttachment(PhysicsConstraint);
	Wheel->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupConstraint();

}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASprungWheel::SetupConstraint()
{
	if (!GetAttachParentActor()) { return; }
	auto BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	PhysicsConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Cast<UPrimitiveComponent>(Wheel), NAME_None);
}

