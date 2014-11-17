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

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info")
    FName ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info")
    FString ItemDescription;
	
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Info")
    FSlateBrush ItemIcon;
};
