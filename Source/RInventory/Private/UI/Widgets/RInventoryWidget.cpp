// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RItem.h"
#include "RInventoryWidget.h"

URInventoryWidget::URInventoryWidget(const FObjectInitializer& ObjectInitializer):
    Super(ObjectInitializer)
{
    bInventoryChanged = false;
    bRebuildGridLayout = true;
}

void URInventoryWidget::AddItem(ARItem* Item)
{
    ItemList.Add(FRItemInfo(Item->Name, "Derpy Dessription", FSlateBrush()));

    bInventoryChanged = true;
}

void URInventoryWidget::PostInitProperties() {
    Super::PostInitProperties();

//    Items.Reserve(MaxInventorySlots);
}

void URInventoryWidget::ToggleVisibility()
{
    if(bInventoryChanged) {
        OnResetLayout();
        bInventoryChanged = false;
    }

    if(bRebuildGridLayout) {
        RebuildGridLayout();
        bRebuildGridLayout = false;
    }
    Super::ToggleVisibility();
}

