// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RInventoryComponent.h"

URInventoryComponent::URInventoryComponent(const FObjectInitializer& ObjectInitializer):
Super(ObjectInitializer)
{
    MaxInventorySlots = 50;
}


void URInventoryComponent::InitializeComponent()
{
    Super::InitializeComponent();

    Inventory.Reserve(MaxInventorySlots);
    for(uint8 CurrentSlot = 0; CurrentSlot < MaxInventorySlots; ++CurrentSlot)
    {
        FRInventorySlot Slot;
        Slot.ItemName = "Empty Item";
   //     Slot.ItemDescription = "No Description";
        Slot.SlotIndex = CurrentSlot;
        Inventory.Add(Slot);
    }
}

void URInventoryComponent::BeginDestroy() {
    Super::BeginDestroy();
}

void URInventoryComponent::AddItem(FRItemInfo ItemInfo) {
    // find an empty inventory slot
    uint8 EmptySlot = GetEmptySlot();

    if(EmptySlot == MaxInventorySlots) {
        // failed
        // blow up
        return;
    }
    FRInventorySlot Slot;
    Slot.ItemName = ItemInfo.ItemName;
    Slot.SlotIndex = EmptySlot;
    Inventory[EmptySlot] = Slot;
}

uint8 URInventoryComponent::GetEmptySlot() {
    for(uint8 CurrentSlot = 0; CurrentSlot < MaxInventorySlots; ++CurrentSlot)
    {
        if(Inventory[CurrentSlot].SlotIndex == 0)
        {
            return CurrentSlot;
        }
    }

    return MaxInventorySlots; 
}

TArray<FRInventorySlot> URInventoryComponent::GetItems() const {
    return Inventory;
}