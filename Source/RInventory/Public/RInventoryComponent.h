// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"

#include "Items/RItemData.h"
#include "RInventoryComponent.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API URInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
    URInventoryComponent(const FObjectInitializer& ObjectInitializer);

    virtual void InitializeComponent() override;
    virtual void BeginDestroy() override;
	
    int32 AddItem(class ARItem* Item);

    TArray<FRInventorySlot> Inventory;

    TArray<class FRItem*> Items; // Inventory Component owns the items.

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Grid")
    int32 MaxInventorySlots;

    int32 GetEmptySlot();
};
