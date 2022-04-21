// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PhotoModeInputData.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPhotoModeInputData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPhotoModeInputData();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Category = "Axis Inputs", GetOptions = "GetAxisInputList"))
	FName ForwardMovement;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Category = "Axis Inputs", GetOptions = "GetAxisInputList"))
	FName LateralMovement;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Category = "Axis Inputs", GetOptions = "GetAxisInputList"))
	FName LookUpRate;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Category = "Axis Inputs", GetOptions = "GetAxisInputList"))
	FName TurnRate; 
		
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Category = "Axis Inputs", GetOptions = "GetAxisInputList"))
	FName CraneUp;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Category = "Axis Inputs", GetOptions = "GetAxisInputList"))
	FName CraneDown;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Category = "Action Inputs", GetOptions = "GetActionInputList"))
	FName HidePhotoModeUI;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Category = "Action Inputs", GetOptions = "GetActionInputList"))
	FName SelectItem;

	UFUNCTION()
	TArray<FName> GetActionInputList();

	UFUNCTION()
	TArray<FName> GetAxisInputList();
};
