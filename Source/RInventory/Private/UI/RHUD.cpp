// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"

#include "RPlayerController.h"
//#include "UI/Widgets/RInventoryWidget.h"
#include "RHUD.h"

ARHUD::ARHUD(const FObjectInitializer& ObjectInitializer):
    Super(ObjectInitializer)
{
   // bShowMouseCursor = false;

}

void ARHUD::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    RPlayerOwner = Cast<ARPlayerController>(GetOwner());

    if(InventoryWidgetType)
    {
        InventoryWidget = CreateWidget<URInventoryWidget>(GetWorld(), InventoryWidgetType);

        // TODO:: Fix this silly hack. Without it Items would only start to show up in Inventory Screen after Toggled once.
        InventoryWidget->ToggleVisibility();
        InventoryWidget->ToggleVisibility();
    }
    else
    {
        // Blow the fuck up
    }
}

void ARHUD::ToggleInventoryScreen()
{
    if(InventoryWidget->GetIsVisible()) {
        // will be hiding widget
        // TODO:: Track all UI widgets open as another one may require mouse cursor to be visible
        //   RPlayerOwner->bShowMouseCursor = false;
        FInputModeGameOnly InputMode;
        RPlayerOwner->SetInputMode(InputMode);
        RPlayerOwner->RPlayer->CameraBoom->bUsePawnControlRotation = true;
    }
    else {
        FInputModeGameAndUI InputMode;
        InputMode.SetLockMouseToViewport(true);
        InputMode.SetHideCursorDuringCapture(true);
        RPlayerOwner->RPlayer->CameraBoom->bUsePawnControlRotation = false;

        InputMode.SetWidgetToFocus(InventoryWidget->TakeWidget());
        RPlayerOwner->SetInputMode(InputMode);
    }
    InventoryWidget->ToggleVisibility();

  //  return bReturn;
}

void ARHUD::MarkInventoryAsChanged() {
    InventoryWidget->MarkInventoryChanged();
}

bool ARHUD::IsMouseCursorVisible() {
    return RPlayerOwner->bShowMouseCursor;
}

bool ARHUD::IsInventoryScreenVisible() {
    return InventoryWidget->GetIsVisible();
}

