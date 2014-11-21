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

    // The index of slot this item takes up in inventory
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    uint8 SlotIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FName ItemName;
};


/** Structure to store the lookup of GameObjects for use in a UDataTable */
USTRUCT(Blueprintable)
struct FRItemTable : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

    /** Full Path of Blueprint */
    UPROPERTY(BlueprintReadOnly, Category = "GO")
    FString ItemName;

    /** Category of GamePlay Object */
    UPROPERTY(BlueprintReadOnly, Category = "GO")
    FString ItemsDescription;
};