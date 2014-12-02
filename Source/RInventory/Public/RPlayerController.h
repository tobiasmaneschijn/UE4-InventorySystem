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
    void BeginPlay() override;

    void PostInitializeComponents() override;
    /* Input **/
    void SetupInputComponent() override;

    void SetPawn(APawn* Pawn) override;

    void ToggleInventoryScreen();

    void OnUse();

    class ARHUD* MyVHUD;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category ="Player")
    class ARInventoryCharacter* RPlayer;

    UFUNCTION(BlueprintCallable, Category = PlayerController)
        virtual ARInventoryCharacter* GetRCharacter();	
};
