// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

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

	// 여기서는 필요가 없으니까 지움
	// UPhysicsHandleComponent *PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	// if (PhysicsHandle != nullptr)
	// {
	// 	UE_LOG(LogTemp, Display, TEXT("Got Physics Handle: %s"), *PhysicsHandle->GetName());
	// 	PhysicsHandle->GetName();
	// }
	// else
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("No Physics Handle Found!"));
	// 	// PhysicsHandle->DestroyComponent();
	// }
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	// physicshandle이 nullptr일때 바로 리턴
	if (PhysicsHandle == nullptr)
	{
		return;
	}

	FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;

	PhysicsHandle->SetTargetLocationAndRotation(TargetLocation, GetComponentRotation());

	// FRotator OwnerRotation = GetComponentRotation();
	// FString RotationString = OwnerRotation.ToCompactString();
	// UE_LOG(LogTemp, Display, TEXT("Camera Rotation is %s"), *RotationString);

	// World Object
	// UWorld 객체를 얻을 수 있습니다.
	// UWorld* world = GetWorld();
	// float MyTime = world->TimeSeconds;
	// UE_LOG(LogTemp, Display, TEXT(" %d"), MyTime);

	// const damage print
	// float Damage;
	// if (HasDamage(Damage))
	// {
	// 	PrintDamage(Damage);
	// }
	// UE_LOG(LogTemp, Display, TEXT("original Damage: %f"), Damage);
	// ...
}

// void UGrabber::PrintDamage(float& Damage)
void UGrabber::PrintDamage(const float &Damage)
{
	// Damage = 2;
	UE_LOG(LogTemp, Display, TEXT("Damage: %f"), Damage);
}

bool UGrabber::HasDamage(float &OutDamage)
{
	OutDamage = 5;
	return true;
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Display, TEXT("Released grabber"));
}

void UGrabber::Grab()
{
	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	// physicshandle이 nullptr일때 바로 리턴
	if (PhysicsHandle == nullptr)
	{
		return;
	}

	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);
	DrawDebugSphere(GetWorld(), End, 10, 10, FColor::Blue, false, 5);

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start, End,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Sphere);

	if (HasHit)
	{
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			HitResult.GetComponent(),
			NAME_None,
			HitResult.ImpactPoint,
			GetComponentRotation()
		);
		// DrawDebugSphere(GetWorld(), HitResult.Location, 10, 10, FColor::Green, false, 5);
		// DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10, 10, FColor::Red, false, 5);
		// AActor *MyActor = HitResult.GetActor();
		// UE_LOG(LogTemp, Display, TEXT("Hit actor: %s"), *MyActor->GetActorNameOrLabel());
	}
	// else
	// {
	// 	UE_LOG(LogTemp, Display, TEXT("No Actor hit"));
	// }
}

UPhysicsHandleComponent* UGrabber::GetPhysicsHandle() const
{
	UPhysicsHandleComponent* Result = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (Result == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Grabber requires a UPhysicsHandleComponent."));
	}
	return Result;
}
