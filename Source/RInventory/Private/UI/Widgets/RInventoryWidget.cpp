// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RItem.h"
#include "RInventoryWidget.h"

void URInventoryWidget::AddItem(ARItem* Item) {

    UE_LOG(RLog, Warning, TEXT("Added Item!"));

    ItemList.Add(FRItemData(Item->Name));

    OnAddItem(Item); // Notify blueprints of added Item

    bInventoryChanged = true;
}

void URInventoryWidget::PostInitProperties() {
    Super::PostInitProperties();

    Items.Reserve(MaxInventorySlots);
}

void URInventoryWidget::ToggleVisibility()
{
    UE_LOG(RLog, Warning, TEXT("INventoryWidget Toggle Visibility!"));
    if(bInventoryChanged) {
        UE_LOG(RLog, Warning, TEXT("Reset Layout!"));
        OnResetLayout();
        bInventoryChanged = false;
    }
    Super::ToggleVisibility();
}

