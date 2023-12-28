// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    UE_LOG(LogTemp, Display, TEXT("Constructing"));

	// ...
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

    UE_LOG(LogTemp, Display, TEXT("Trigger Component : BeginPlay"));
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // UE_LOG(LogTemp, Display, TEXT("Trigger Component Is Ticking Here"));

	// TArray 
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	// 겹치는 object가 1개 이상 있을 때만 출력하도록 만들기
	// if (Actors.Num() > 0)
	// {
	// 	FString actorName = Actors[0]->GetActorNameOrLabel();
	// 	UE_LOG(LogTemp, Display, TEXT("OverlappedObject : %s"), *actorName);
	// }

	// int32 index = 0;
	// while (index < Actors.Num())
	// {
	// 	FString actorName = Actors[index]->GetActorNameOrLabel();
	// 	UE_LOG(LogTemp, Display, TEXT("OverlappedObject : %s"), *actorName);
	// 	++index;
	// }

	// for (int32 i = 0; i < Actors.Num(); i++)
	// {
	// 	FString actorName = Actors[i]->GetActorNameOrLabel();
	// 	UE_LOG(LogTemp, Display, TEXT("OverlappedObject : %s"), *actorName);
	// }
	
	// range based for loop
	for (AActor* Actor : Actors)
	{
		FString actorName = Actor->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("OverlappedObject : %s"), *actorName);
	}

}