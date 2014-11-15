// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RPlayerController.h"

#include "Items/RItem.h"

void ARPlayerController::PostInitializeComponents()
{
    Super::PostInitializeComponents();

}

void ARPlayerController::BeginPlay()
{
    Super::BeginPlay();

    MyVHUD = Cast<ARHUD>(MyHUD);
    VPlayer = Cast<ARInventoryCharacter>(Player);
}

void ARPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    //InputComponent->BindAction("ShowInventory", IE_Pressed, this, &AVPlayerController::ToggleInventoryScreen);
    InputComponent->BindAction("Use", IE_Pressed, this, &ARPlayerController::OnUse);
}

void ARPlayerController::ToggleInventoryScreen()
{
    if(MyHUD != NULL && Cast<ARHUD>(MyHUD) != NULL)
    {
        Cast<ARHUD>(MyHUD)->ToggleInventoryScreen();
    }
}

void ARPlayerController::OnUse() {

    GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("PC ON USE!"));
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
        if(!VPlayer) {
            VPlayer = Cast<ARInventoryCharacter>(Player);
            UE_LOG(RLog, Warning, TEXT("VPLAYER NOT SET!"));
        }
        //VPlayer->PickupItem(UsableItem);
        UsableItem->PickedUp();
        //	UE_LOG(ValhallaLog, Warning, TEXT("Actor's Name is %s"), *Hit.GetActor()->GetName());
    }
    	if (Hit.Actor != NULL) {
    	    UE_LOG(RLog, Warning, TEXT("Actor's Name is %s"), *Hit.GetActor()->GetName());
    	}
    //else {
    //	UE_LOG(ValhallaLog, Warning, TEXT("No Actor"));
    //}
    //return DidTrace;

}