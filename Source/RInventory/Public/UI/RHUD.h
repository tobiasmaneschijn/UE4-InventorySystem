// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"

#include "UI/Widgets/RInventoryWidget.h"
#include "RHUD.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API ARHUD : public AHUD
{
	GENERATED_BODY()
	
public:

    void PostInitializeComponents() override;

    void ToggleInventoryScreen();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
    TSubclassOf<class UUserWidget> InventoryWidgetType;

    UPROPERTY()
    URInventoryWidget* InventoryWidget;

    void MarkInventoryWidgetDirty();

protected:
    class ARPlayerController* RPlayerOwner;

    bool bIsInventoryWidgetDirty;
	
};
