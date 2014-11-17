// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RItemData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FRItemData
{
	GENERATED_USTRUCT_BODY()
	
public:

    FRItemData() :
        ItemName("Name Not Set")
   {

    }
    FRItemData(FName Name):
        ItemName(Name)
    {

    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "wtfsauce")
    FName ItemName;
	
	
};
