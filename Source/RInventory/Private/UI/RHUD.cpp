// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"

#include "RPlayerController.h"
//#include "UI/Widgets/RInventoryWidget.h"
#include "RHUD.h"

void ARHUD::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    RPlayerOwner = Cast<ARPlayerController>(GetOwner());

    if(InventoryWidgetType)
    {
        InventoryWidget = CreateWidget<URInventoryWidget>(GetWorld(), InventoryWidgetType);
        InventoryWidget->AddToViewport();
    }
    else
    {
        // Blow the fuck up
    }
}

void ARHUD::ToggleInventoryScreen()
{
    // TODO: Track all UI Widgets to determine if we should keep mouse cursor visible 
    // as well as stopping game input!
    if(InventoryWidget->bIsVisible) {
        // hide mouse cursor
        FInputModeGameOnly InputMode;
        RPlayerOwner->SetInputMode(InputMode);
        RPlayerOwner->bShowMouseCursor = false;
    }
    else {
        FInputModeGameAndUI InputMode;
        InputMode.SetLockMouseToViewport(true);
        InputMode.SetHideCursorDuringCapture(true);
        InputMode.SetWidgetToFocus(InventoryWidget->TakeWidget());
        RPlayerOwner->SetInputMode(InputMode);
        RPlayerOwner->bShowMouseCursor = true;
    }
    InventoryWidget->ToggleVisibility();
}

void ARHUD::MarkInventoryAsChanged() {
    InventoryWidget->MarkInventoryChanged();
}