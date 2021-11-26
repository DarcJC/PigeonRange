// Copyright Epic Games, Inc. All Rights Reserved.

#include "PigeonGameMode.h"
#include "PigeonCharacter.h"
#include "UObject/ConstructorHelpers.h"

APigeonGameMode::APigeonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
