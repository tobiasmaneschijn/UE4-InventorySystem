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
* This is a slot within InventoryComponent
*/
USTRUCT(BlueprintType)
struct FRInventorySlot
{
    GENERATED_USTRUCT_BODY()

public:
    FRInventorySlot():
        SlotIndex(-1),
        ItemName("Item Name Not Set"),
        ItemIcon()
    {
    }
    // The index of slot this item takes up in inventory
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    int32 SlotIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Inventory")
    FSlateBrush ItemIcon;

};