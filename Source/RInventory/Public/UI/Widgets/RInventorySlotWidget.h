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
    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnSetText(const FString& Text);

    UFUNCTION(BlueprintCallable, Category = "Functions")
    void TestCallable();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meta")
    FString ItemName;
	
	
	
};
