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

        // TODO:: Fix this silly hack. Without it Items would only start to show up in Inventory Screen after Toggled once.
        InventoryWidget->ToggleVisibility();
        InventoryWidget->ToggleVisibility();
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