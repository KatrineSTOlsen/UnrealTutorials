// Copyright Katrine Olsen 2018

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();
	FRotator NewRotation = FRotator(0.0f, -60.0f, 0.0f);
	Owner->SetActorRotation(NewRotation);
}

void UOpenDoor::CloseDoor()
{

	FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastTimeOpen = GetWorld()->GetTimeSeconds();
	}
	else if (CloseDoorDelay < GetWorld()->GetTimeSeconds() - LastTimeOpen)
	{
		CloseDoor();
	}
	// poll the triggervolume every frame 
	//if the actor that opens is in the volume

}

