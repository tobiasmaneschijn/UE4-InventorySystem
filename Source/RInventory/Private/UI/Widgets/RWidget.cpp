// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RWidget.h"

URWidget::URWidget(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{

}


void URWidget::ToggleVisibility()
{
    if(bIsVisible)
    {
        SetVisibility(ESlateVisibility::Collapsed);
        bIsVisible = false;
    }
    else
    {
        SetVisibility(ESlateVisibility::Visible);
        bIsVisible = true;
    }
}




