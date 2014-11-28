// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RWidget.h"

URWidget::URWidget(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{

}
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

bool URWidget::DoesTakeMouseFocus() const {
    return bTakesMouseFocus;
}

bool URWidget::DoesDisableCameraMovement() const {
    return bDisablesCameraMovement;
}