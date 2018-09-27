// Copyright Katrine Olsen 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"

#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SECTION01_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();
	float GetTotalMassOfActorsOnPlate();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpenRequest;
private:
	UPROPERTY(EditAnywhere)
		float OpenAngle = -90.0f;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;
	UPROPERTY(EditAnywhere)
		float CloseDoorDelay = 0.5f;
	UPROPERTY(EditAnywhere)
		float TriggerMass = 60.f;


	float LastTimeOpen;
	AActor* Owner = GetOwner();
};