// Copyright Epic Games, Inc. All Rights Reserved.

#include "PluginGameMode.h"
#include "PluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

APluginGameMode::APluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
