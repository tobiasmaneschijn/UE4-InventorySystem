// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RItem.h"
#include "RInventoryComponent.h"

URInventoryComponent::URInventoryComponent(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{
    MaxInventorySlots = 50;
}


void URInventoryComponent::InitializeComponent()
{
    Super::InitializeComponent();

    Inventory.Reserve(MaxInventorySlots);
    for(int32 CurrentSlot = 0; CurrentSlot < MaxInventorySlots; ++CurrentSlot)
    {
        FRInventorySlot Slot;
        Slot.SlotIndex = -1; // set it as not set
        Inventory.Add(Slot);
    }
}

void URInventoryComponent::BeginDestroy() {
    Super::BeginDestroy();
}

int32 URInventoryComponent::AddItem(ARItem* Item) {
    // find an empty inventory slot
    int32 EmptySlot = GetEmptySlot();

    if(EmptySlot == -1) {
        // failed
        // blow up
        return -1;
    }
    
    FRInventorySlot Slot;
    Slot.DisplayInfo.ItemName = Item->DisplayInfo.ItemName;
    Slot.SlotIndex = EmptySlot;
    Slot.DisplayInfo.ItemIcon = Item->DisplayInfo.ItemIcon;
    Inventory[EmptySlot] = Slot;

    // add item to Items array

    return EmptySlot;
}

int32 URInventoryComponent::GetEmptySlot() {
    for(int32 CurrentSlot = 0; CurrentSlot < MaxInventorySlots; ++CurrentSlot)
    {
        if(Inventory[CurrentSlot].SlotIndex == -1)
        {
            return CurrentSlot;
        }
    }

    return -1; 
}

FRInventorySlot URInventoryComponent::GetItemInfoFromSlot(int32 SlotIndex) {
    if(SlotIndex > Inventory.Num()) {
        // blow up
    }

    return Inventory[SlotIndex];
}