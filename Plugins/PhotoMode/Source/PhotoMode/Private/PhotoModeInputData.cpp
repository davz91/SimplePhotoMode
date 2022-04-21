// Fill out your copyright notice in the Description page of Project Settings.


#include "PhotoModeInputData.h"

#include "GameFramework/InputSettings.h"


UPhotoModeInputData::UPhotoModeInputData()
{
	
}

TArray<FName> UPhotoModeInputData::GetActionInputList()
{
	TArray<FName> InputList;

	GetDefault<UInputSettings>()->GetActionNames(InputList);
	InputList.Insert(NAME_None, 0);

	return InputList;
}

TArray<FName> UPhotoModeInputData::GetAxisInputList()
{
	TArray<FName> AxisList;

	GetDefault<UInputSettings>()->GetAxisNames(AxisList);
	AxisList.Insert(NAME_None, 0);

	return AxisList;
}
