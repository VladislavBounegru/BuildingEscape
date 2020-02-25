// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"

#define OUT
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

	if (!PressurePlate) 
	{ 
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName());
	}

	Owner = GetOwner();	
}





// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if(GetTotalMassOfActorsOnPlate() > TriggerMass)
	{
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}
	
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() 
{
	float TotalMass = 0.f;

	// find all the overlaping actors
	TArray<AActor*> OverlappingActors;

	if (!PressurePlate) { return 0.f; }
	PressurePlate->GetOverlappingActors
	(
		OUT OverlappingActors
	);
	
	// Iterate through them adding their masses
	for (const auto* Actor:OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		//UE_LOG(LogTemp, Warning, TEXT("%s on pressureplate"), *Actor->GetName());
	}
	
		
	return TotalMass;
}