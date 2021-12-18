// Fill out your copyright notice in the Description page of Project Settings.


#include "PigeonHealComponent.h"

#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UPigeonHealComponent::UPigeonHealComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Health = 100.0f;
	Armor = .0f;
}


float UPigeonHealComponent::CalcDamageBlocked(float Value)
{
	return Armor > 1.0f ? Value / Armor : .0f;
}

void UPigeonHealComponent::GetDamage_Implementation(float Value, APigeonCharacter* Controller = nullptr)
{
	if (Value > .0f)
	{
		const float Result = Health - Value + CalcDamageBlocked(Value);
		Health = (Result > .0f) ? Result : .0f;
	}
	if (Controller) LastDamageSource = Controller;
}

// float UPigeonHealComponent::GetDamage(float Value)
// {
// 	if (Value > .0f)
// 	{
// 		const float Result = Health - Value + CalcDamageBlocked(Value);
// 		const float OldHealth = Health; 
// 		Health = (Result > .0f) ? Result : .0f;
// 		return OldHealth - Health;
// 	}
// 	return .0f;
// }

// Called when the game starts
void UPigeonHealComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

float UPigeonHealComponent::GetHealthValue()
{
	return Health;
}

APigeonCharacter* UPigeonHealComponent::GetLastDamageSource()
{
	return LastDamageSource;
}


// Called every frame
void UPigeonHealComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPigeonHealComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UPigeonHealComponent, Health);
	DOREPLIFETIME(UPigeonHealComponent, LastDamageSource);
}

