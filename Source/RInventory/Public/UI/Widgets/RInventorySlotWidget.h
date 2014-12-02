// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/Widgets/RWidget.h"
#include "RInventorySlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API URInventorySlotWidget : public URWidget
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inv Slot")
    FSlateBrush ItemIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inv Slot")
    int32 SlotIndex;
};
