// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "RInventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API URInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION(Category = "Items")
	void AddItem();

    void ToggleVisibility();
};
