// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/Widgets/RWidget.h"
#include "RItemData.h"
#include "RInventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API URInventoryWidget : public URWidget
{
	GENERATED_BODY()

public:
    URInventoryWidget(const FObjectInitializer& ObjectInitializer);
    void PostInitProperties() override;

    UFUNCTION(Category = "Items")
    void AddItem(class ARItem* Item);

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnResetLayout();

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnAddedItem(FRItemInfo ItemInfo);

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void RebuildGridLayout();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    TArray<FRItemInfo> ItemList;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory Layout", Meta = (DisplayName = "Total Slots"))
    int32 MaxInventorySlots;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory Layout", Meta = (DisplayName = "Column Count"))
    int32 ColumnCount;

    bool bInventoryChanged;

    bool bRebuildGridLayout;

    void ToggleVisibility() override;

    void SetInventory(TArray<FRInventorySlot> ItemArray);
	
	
};
