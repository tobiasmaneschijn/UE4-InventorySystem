// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RItemData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FRItemDisplayInfo
{
	GENERATED_USTRUCT_BODY()
	
public:

    FRItemDisplayInfo():
        ItemName("Default Item Name"),
        ItemDescription("Default Item Description"),
        ItemIcon()
    {

    }
    
    FRItemDisplayInfo(FString Name, FString Description, FSlateBrush Icon):
        ItemName(Name),
        ItemDescription(Description),
        ItemIcon(Icon)
    {

    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FString ItemDescription;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FSlateBrush ItemIcon;
};

/**
* This is a slot within InventoryComponent
*/
USTRUCT(BlueprintType)
struct FRInventorySlot
{
    GENERATED_USTRUCT_BODY()

public:
    FRInventorySlot() :
        DisplayInfo(),
        SlotIndex(-1)
    {
    }

    // Basic info about item like name, description, and icon
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FRItemDisplayInfo DisplayInfo;

    // The index of slot this item takes up in inventory
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    int32 SlotIndex;
};

/** Structure that defines a level up table entry */
USTRUCT(BlueprintType)
struct FRItemData : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:

    FRItemData()
        : Name()
        , Description()
    {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    FString Description;
};