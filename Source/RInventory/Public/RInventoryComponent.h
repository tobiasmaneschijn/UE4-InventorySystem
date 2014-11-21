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
	
    void AddItem(FRItemInfo ItemInfo);

    TArray<FRInventorySlot> Inventory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Grid")
    uint8 MaxInventorySlots;

    uint8 GetEmptySlot();

    TArray<FRInventorySlot> GetItems() const;
};
