// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/Widgets/RWidget.h"
#include "RItemHoverPanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API URItemHoverPanelWidget : public URWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemInfo)
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemInfo)
    FString ItemDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemInfo)
    FSlateBrush ItemIcon;
};
