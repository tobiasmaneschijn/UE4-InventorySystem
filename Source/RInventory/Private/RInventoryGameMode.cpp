// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "RInventory.h"
#include "RInventoryGameMode.h"

#include "RHUD.h"
#include "RPlayerController.h"
#include "RInventoryCharacter.h"

ARInventoryGameMode::ARInventoryGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

   static ConstructorHelpers::FClassFinder<AHUD> RHUDBPClass(TEXT("/Game/Blueprints/UI/BP_HUD"));

   if(RHUDBPClass.Class != NULL) {
       HUDClass = RHUDBPClass.Class;
   }

   PlayerControllerClass = ARPlayerController::StaticClass();
}
