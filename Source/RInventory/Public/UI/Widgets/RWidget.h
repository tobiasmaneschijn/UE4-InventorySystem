// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "RWidget.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API URWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

    virtual void ToggleVisibility();

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnAddedToViewport();

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnRemovedFromViewport();

	
};
