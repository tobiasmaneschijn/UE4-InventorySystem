// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RItemData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FRItemInfo
{
	GENERATED_USTRUCT_BODY()
	
public:

    FRItemInfo() :
        ItemName("Default Item Name"),
        ItemDescription("Default Item Description"),
        ItemIcon()
    {

    }
    
    FRItemInfo(FName Name, FString Description, FSlateBrush Icon) :
        ItemName(Name),
        ItemDescription(Description),
        ItemIcon(Icon)
    {

    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FName ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FString ItemDescription;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FSlateBrush ItemIcon;
};

/**
*
*/
USTRUCT(BlueprintType)
struct FRInventorySlot
{
    GENERATED_USTRUCT_BODY()

public:
    FRInventorySlot():
        SlotIndex(0),
        ItemName("Item Name Not Set")
    {
    }
    // The index of slot this item takes up in inventory
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    int32 SlotIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FName ItemName;
};


/**
 *
 * This is a slot in the inventory of UI Widget. It contains all data needed to display an item if hovered.
 *
**/
USTRUCT(BlueprintType)
struct FRItemInventorySlot 
{
    GENERATED_USTRUCT_BODY()

public:
    FRItemInventorySlot():
        ItemName("Default Name"),
        ItemIcon(),
        bIsEmpty(true)
    {

    }

    FRItemInventorySlot(FName Name, int32 Index):
        ItemName(Name),
        ItemIcon(),
        bIsEmpty(true)
    {

    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Inventory")
    FName ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Inventory")
    FSlateBrush ItemIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Inventory")
    bool bIsEmpty;
};