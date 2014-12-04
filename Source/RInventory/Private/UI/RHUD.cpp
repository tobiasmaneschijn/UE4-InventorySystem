// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"

#include "RPlayerController.h"
//#include "UI/Widgets/RInventoryWidget.h"
#include "RHUD.h"

void ARHUD::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    RPlayerOwner = Cast<ARPlayerController>(GetOwner());

    if(InventoryWidgetType)
    {
        InventoryWidget = CreateWidget<URInventoryWidget>(GetWorld(), InventoryWidgetType);
        InventoryWidget->AddToViewport();
    }
    else
    {
        // Blow the fuck up
    }
}

void ARHUD::ToggleInventoryScreen()
{
    InventoryWidget->ToggleVisibility();
}

void ARHUD::MarkInventoryAsChanged() {
    InventoryWidget->MarkInventoryChanged();
}