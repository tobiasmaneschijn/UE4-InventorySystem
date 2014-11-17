// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"

//#include "UI/Widgets/RInventoryWidget.h"
#include "RHUD.h"

void ARHUD::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    if(InventoryWidgetType)
    {
        InventoryWidget = CreateWidget<URInventoryWidget>(GetWorld(), InventoryWidgetType);
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