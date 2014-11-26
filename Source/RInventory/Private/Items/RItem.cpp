// Fill out your copyright notice in the Description page of Project Settings.

#include "RInventory.h"
#include "RItem.h"

ARItem::ARItem(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    StaticMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMesh"));
    RootComponent = StaticMesh;
}

void ARItem::BeginPlay()
{
    Super::BeginPlay();
}

void ARItem::PickedUp()
{
    Destroy();
}

void ARItem::Dropped()
{
   // StaticMesh->SetHiddenInGame(false);
}


