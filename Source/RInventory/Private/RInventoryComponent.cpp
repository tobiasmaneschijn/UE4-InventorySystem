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
        Slot.ItemName = "Empty Item";
   //     Slot.ItemDescription = "No Description";
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

    UE_LOG(RLog, Warning, TEXT("URInventoryComponent[AddSlot] Empty Slot: %d "), EmptySlot);

    if(EmptySlot == -1) {
        // failed
        // blow up
        return -1;
    }
    
    FRInventorySlot Slot;
    Slot.ItemName = Item->ItemName;
    Slot.SlotIndex = EmptySlot;
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