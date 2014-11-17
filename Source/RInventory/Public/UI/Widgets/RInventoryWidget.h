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

    void PostInitProperties() override;

    UFUNCTION(Category = "Items")
        void AddItem(class ARItem* Item);

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnAddItem(class ARItem* Item);

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnResetLayout();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    TArray<class ARItem*> Items;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    TArray<FRItemData> ItemList;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    uint32 MaxInventorySlots;


    bool bInventoryChanged;

    void ToggleVisibility() override;
	
	
};
