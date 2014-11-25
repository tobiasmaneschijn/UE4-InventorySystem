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
}

void URInventoryWidget::ToggleVisibility()
{
    if(bInventoryChanged) {
        UE_LOG(RLog, Warning, TEXT("Toggle Vis bInvchanged - InventoryWidget"));
        OnPopulateGrid();

        bInventoryChanged = false;
    }

    if(bRebuildGridLayout) {
        RebuildGridLayout();
        bRebuildGridLayout = false;
    }
    Super::ToggleVisibility();
}