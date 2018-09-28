// Copyright Katrine Olsen 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"

#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpen);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClose);

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

	float GetTotalMassOfActorsOnPlate();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
	UPROPERTY(BlueprintAssignable)
		FOnOpen OnOpen;
	UPROPERTY(BlueprintAssignable)
		FOnClose OnClose;

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;
	UPROPERTY(EditAnywhere)
		float TriggerMass = 60.f;

	AActor* Owner = GetOwner();
};