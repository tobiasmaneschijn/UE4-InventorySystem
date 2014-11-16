// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RInventoryWidget.h"

void URInventoryWidget::AddItem(ARItem* Item) {

    Items.Add(Item);

    OnAddItem(Item); // Notify blueprints of added Item
}

void URInventoryWidget::PostInitProperties() {
    Super::PostInitProperties();

    Items.Reserve(MaxInventorySlots);
}


