// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PigeonMultiplayerController.generated.h"

/**
 * 
 */
UCLASS()
class PIGEON_API APigeonMultiplayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure)
	FString GetNetworkURL() const;
	
};
