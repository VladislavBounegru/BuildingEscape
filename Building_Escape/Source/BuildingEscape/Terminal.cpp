// Fill out your copyright notice in the Description page of Project Settings.


#include "Terminal.h"
#include "CollisionQueryParams.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
ATerminal::ATerminal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATerminal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATerminal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATerminal::OpenDoor()
{
	Physicshandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}

 void ATerminal::GetFirstPhysicsBodyInReach()
{
	return ;
}

