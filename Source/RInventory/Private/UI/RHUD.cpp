// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"

//#include "UI/Widgets/RInventoryWidget.h"
#include "RHUD.h"

void ARHUD::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    if(InventoryWidgetType)
    {
        UE_LOG(RLog, Warning, TEXT("InventorWidgetType!"));
        InventoryWidget = CreateWidget<URInventoryWidget>(GetWorld(), InventoryWidgetType);
    }
    else
    {
        UE_LOG(RLog, Error, TEXT("InventorWidgetType not set!"));
        // Blow the fuck up
    }

}

void ARHUD::ToggleInventoryScreen()
{
    UE_LOG(RLog, Warning, TEXT("InvScreen Toggle"));
    InventoryWidget->ToggleVisibility();
}