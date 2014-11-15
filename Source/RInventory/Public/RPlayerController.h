// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"

#include "UI/RHUD.h"
#include "RInventoryCharacter.h"

#include "RPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API ARPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;

    virtual void PostInitializeComponents() override;
    /* Input **/
    virtual void SetupInputComponent() override;

    void ToggleInventoryScreen();

    void OnUse();

    UPROPERTY()
    class ARHUD* MyVHUD;

    ARInventoryCharacter* VPlayer;
	
};
