// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RWidget.h"

void URWidget::ToggleVisibility()
{
    if(GetIsVisible())
    {
        UE_LOG(RLog, Warning, TEXT("Removed from screen!"));
        RemoveFromViewport();
    }
    else
    {
        UE_LOG(RLog, Warning, TEXT("Added to screen!"));

        AddToViewport();
    } 
}




