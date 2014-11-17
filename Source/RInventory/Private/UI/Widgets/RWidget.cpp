// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RWidget.h"

void URWidget::ToggleVisibility()
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




