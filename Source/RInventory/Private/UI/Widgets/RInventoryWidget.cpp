// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"

#include "RItem.h"
#include "RInventoryWidget.h"


void URInventoryWidget::AddItem(ARItem* Item) {

    OnAddItem(Item); // Notify blueprints of added Item
}

void URInventoryWidget::ToggleVisibility()
{
    if(GetIsVisible())
    {
        RemoveFromViewport();
    }
    else
    {
        AddToViewport();
    }
}

