// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Items/RItemData.h"

#include "RItem.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API ARItem : public AActor
{
    GENERATED_BODY()
	
public:
    ARItem(const FObjectInitializer& ObjectInitializer);

    UFUNCTION()
    void PickedUp();

    UFUNCTION()
    void Dropped();

    void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
    FRItemDisplayInfo DisplayInfo;

 //   UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
 //   FSlateBrush ItemIcon;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
    bool bIsEquipable;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    class UStaticMeshComponent* StaticMesh;
	
	
};
