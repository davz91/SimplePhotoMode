// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "CameraPawn.generated.h"

class UCameraComponent;
class USphereComponent;
class USpringArmComponent;
class UPhotoModeInputData;

UCLASS()
class PHOTOMODE_API ACameraPawn : public APawn
{
	GENERATED_BODY()

	// Collision 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pawn, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereComponent;

	// SprintArm Component
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UFloatingPawnMovement* MovementComponent;

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Category = "Input Setup"))
	UPhotoModeInputData* InputDataSetupDataAsset = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void BindInputs(UInputComponent* OwnerInputComponent);
	
	void MoveForward(float Scale);
	void MoveRight(float Scale);

	void Turn(float Scale);
	void LookUp(float Scale);

	void CraneMovement(float Scale);

	void HidePhotoUI();
};
