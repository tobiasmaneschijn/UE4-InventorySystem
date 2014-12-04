// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RItem.h"
#include "RInventoryWidget.h"

URInventoryWidget::URInventoryWidget(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{
    bInventoryChanged = false;
    bRebuildGridLayout = true;
}

void URInventoryWidget::Construct_Implementation() 
{

}

void URInventoryWidget::PostInitProperties() {
    Super::PostInitProperties();
}

void URInventoryWidget::ToggleVisibility()
{
    if(bInventoryChanged) {
        OnPopulateInventoryGrid(); // Redraw item icons
        bInventoryChanged = false;
    }

    if(bRebuildGridLayout) {
        OnInventoryGridSlotCountChanged(); // Called when slot count has changed
        bRebuildGridLayout = false;
    }
    Super::ToggleVisibility();
}

void URInventoryWidget::MarkInventoryChanged()
{
    bInventoryChanged = true;
}