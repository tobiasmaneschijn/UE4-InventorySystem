// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RInventoryWidget.h"


void URInventoryWidget::AddItem() {

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

