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
    Inventory.Reserve(MaxInventorySlots);

    // make grid blank initially
    for(int32 CurrentSlot = 0; CurrentSlot < MaxInventorySlots; ++CurrentSlot)
    {
        FRItemInventorySlot Slot;
        Inventory.Add(Slot);
    }
}

void URInventoryWidget::AddItem(ARItem* Item, int32 SlotIndex)
{
    FRItemInventorySlot Slot;
    Slot.ItemName = Item->ItemName;
    Slot.bIsEmpty = false;
    Slot.ItemIcon = Item->ItemIcon;

    Inventory[SlotIndex] = Slot;

    bInventoryChanged = true;
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