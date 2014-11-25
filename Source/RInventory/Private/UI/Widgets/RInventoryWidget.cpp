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

void URInventoryWidget::AddItem(ARItem* Item, int32 SlotIndex)
{
    FRItemInventorySlot Slot;
    Slot.ItemName = Item->Name;
    Slot.bIsEmpty = false;

    UE_LOG(RLog, Warning, TEXT("URInventoryWidget[AddItem] slot: %d"), SlotIndex);
    Inventory[SlotIndex] = Slot;

  //  Inventory[ItemInfo->]
    bInventoryChanged = true;

    //OnAddedItem();
}

void URInventoryWidget::PostInitProperties() {
    Super::PostInitProperties();

    Inventory.Reserve(MaxInventorySlots);

    for(int32 CurrentSlot = 0; CurrentSlot < MaxInventorySlots; ++CurrentSlot) 
    {
        FRItemInventorySlot Slot;
        Inventory.Add(Slot);
    }

    UE_LOG(RLog, Warning, TEXT("URInventoryWidget[PostInitProperties]"));
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