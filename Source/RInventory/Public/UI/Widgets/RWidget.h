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

    URWidget(const FObjectInitializer& ObjectInitializer);

    virtual void ToggleVisibility();

    bool DoesTakeMouseFocus() const;

    bool DoesDisableCameraMovement() const;
protected:
    bool bDisablesCameraMovement;
    bool bTakesMouseFocus;
};
