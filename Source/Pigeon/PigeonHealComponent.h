// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PigeonCharacter.h"
#include "Components/ActorComponent.h"
#include "PigeonHealComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIGEON_API UPigeonHealComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPigeonHealComponent();

	UPROPERTY(EditAnywhere, Replicated)
	float Health;

	UPROPERTY(EditAnywhere)
	float Armor;

	UPROPERTY(EditAnywhere, Replicated)
	APigeonCharacter* LastDamageSource;

	// 计算护甲减伤
	float CalcDamageBlocked(float Value);

	// 受到伤害
	UFUNCTION(BlueprintCallable, Reliable, Server)
	void GetDamage(float Value, APigeonCharacter* Controller);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	float GetHealthValue();

	UFUNCTION(BlueprintCallable)
	APigeonCharacter* GetLastDamageSource();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
