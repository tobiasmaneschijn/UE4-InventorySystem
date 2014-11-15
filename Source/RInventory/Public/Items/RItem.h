// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RItem.generated.h"

/**
 * 
 */
UCLASS()
class RINVENTORY_API ARItem : public AActor
{
    GENERATED_UCLASS_BODY()
	
public:

    UFUNCTION()
    void PickedUp();

    UFUNCTION()
    void Dropped();

    void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Item")
    FName Name;

    UPROPERTY(EditAnywhere, Category = "Item")
    FString Description;

    UPROPERTY(EditAnywhere, Category = "Item")
    bool bIsEquipable;

    //UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    //TSubobjectPtr<class UBoxComponent> BoxComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    class UStaticMeshComponent* StaticMesh;
	
	
};
