// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RPlayerController.h"

#include "Items/RItem.h"

void ARPlayerController::PostInitializeComponents()
{
    Super::PostInitializeComponents();
}

void ARPlayerController::SetPawn(APawn* Pawn) {
    Super::SetPawn(Pawn);

    RPlayer = Cast<ARInventoryCharacter>(Pawn);
}

void ARPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    MyVHUD = Cast<ARHUD>(MyHUD);
}

void ARPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("InventoryScreen", IE_Pressed, this, &ARPlayerController::ToggleInventoryScreen);
    InputComponent->BindAction("Use", IE_Pressed, this, &ARPlayerController::OnUse);
}

void ARPlayerController::ToggleInventoryScreen()
{
    if(MyHUD != NULL && Cast<ARHUD>(MyHUD) != NULL)
    {
        Cast<ARHUD>(MyHUD)->ToggleInventoryScreen();
    }
}

void ARPlayerController::OnUse() 
{    
    FVector camLoc;
    FRotator camRot;
    GetPlayerViewPoint(camLoc, camRot);

    const FVector start_trace = camLoc;
    const FVector direction = camRot.Vector();
    const FVector end_trace = start_trace + (direction * 800.0f);

    FCollisionQueryParams TraceParams(FName(TEXT("USE_TRACE")), true, this);
    TraceParams.bTraceAsyncScene = true;
    TraceParams.bReturnPhysicalMaterial = false;
    TraceParams.bTraceComplex = true;
    TraceParams.AddIgnoredActor(GetPawn());
    FHitResult Hit(ForceInit);
    GetWorld()->LineTraceSingle(Hit, start_trace, end_trace, TRACE_USABLE_ACTOR, TraceParams);

    DrawDebugLine(GetWorld(), start_trace, end_trace, FColor(0, 0, 255), true, 1);

    if(ARItem* UsableItem = Cast<ARItem>(Hit.GetActor()))
    {
        int32 InventorySlot = RPlayer->PickupItem(UsableItem);
        UsableItem->Description = Hit.GetActor()->GetName();
        // Did player actually pickup the item?
        if(InventorySlot > -1) {
            Cast<ARHUD>(MyHUD)->AddItemToInventory(UsableItem, InventorySlot);

            UsableItem->PickedUp();
        }
    }
}

ARInventoryCharacter* ARPlayerController::GetRCharacter() {
    return RPlayer;
}