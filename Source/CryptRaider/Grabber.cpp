// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Components/SceneComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// FRotator OwnerRotation = GetComponentRotation();
	// FString RotationString = OwnerRotation.ToCompactString();
	// UE_LOG(LogTemp, Display, TEXT("Camera Rotation is %s"), *RotationString);

	// World Object
	// UWorld 객체를 얻을 수 있습니다.
	// UWorld* world = GetWorld();
	// float MyTime = world->TimeSeconds;
	// UE_LOG(LogTemp, Display, TEXT(" %d"), MyTime);

	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance ;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	float Damage = 0;
	float& DamageRef = Damage;
	DamageRef = 5;
	UE_LOG(LogTemp, Display, TEXT("DamageRef: %f, Damage: %f"), DamageRef, Damage);
	// ...
}

