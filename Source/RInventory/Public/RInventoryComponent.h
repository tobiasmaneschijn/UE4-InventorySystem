// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "RInventoryComponent.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API URInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
    virtual void InitializeComponent() override;
    virtual void BeginDestroy() override;
	
    void AddItem();
	
};
