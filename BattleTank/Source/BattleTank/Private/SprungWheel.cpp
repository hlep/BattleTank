// Do What The Fuck You Want To Public License


#include "SprungWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PostPhysics;

	PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("PhysicsConstraint"));
	SetRootComponent(PhysicsConstraint);

	AxleConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("AxleConstraint"));
	Axle = CreateDefaultSubobject<USphereComponent>(TEXT("Axle"));
	Wheel = CreateDefaultSubobject<USphereComponent>(TEXT("Wheel"));
		
	Axle->SetupAttachment(PhysicsConstraint);
	AxleConstraint->SetupAttachment(Axle);
	Wheel->SetupAttachment(Axle);

}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	Wheel->SetNotifyRigidBodyCollision(true);
	Wheel->OnComponentHit.AddDynamic(this, &ASprungWheel::OnHit);

	SetupConstraints();

}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetWorld()->TickGroup == TG_PostPhysics) 
	{
		TotalForceMagnitudeThisFrame = 0;
	}	
}

void ASprungWheel::AddDrivingForce(float ForceMagnitude)
{
	TotalForceMagnitudeThisFrame += ForceMagnitude;
}

void ASprungWheel::SetupConstraints()
{
	if (!GetAttachParentActor()) { return; }
	auto BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	PhysicsConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Cast<UPrimitiveComponent>(Axle), NAME_None);
	AxleConstraint->SetConstrainedComponents(Cast<UPrimitiveComponent>(Axle), NAME_None, Cast<UPrimitiveComponent>(Wheel), NAME_None);
}

void ASprungWheel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ApplyForce();
}

void ASprungWheel::ApplyForce()
{
	Wheel->AddForce(Axle->GetForwardVector() * TotalForceMagnitudeThisFrame);
}
