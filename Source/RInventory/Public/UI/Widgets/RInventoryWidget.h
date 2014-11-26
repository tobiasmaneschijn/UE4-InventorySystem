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

    void Construct_Implementation() override;    
    void PostInitProperties() override;

    void MarkInventoryChanged();

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnPopulateInventoryGrid();

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnInventoryGridSlotCountChanged();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory Layout", Meta = (DisplayName = "Total Slots"))
    int32 MaxInventorySlots;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory Layout", Meta = (DisplayName = "Column Count"))
    int32 ColumnCount;

    bool bInventoryChanged;

    bool bRebuildGridLayout;

    void ToggleVisibility() override;
};
