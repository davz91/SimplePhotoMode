// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PhotoModeInputData.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Getting the sames vales a default character would be. So we could argue this should be a character, however, we don't really need most of its functionality nor components, like the mesh.
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CameraCollision"));
	SphereComponent->SetSphereRadius(25.0f, false);
	SphereComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

	SphereComponent->CanCharacterStepUpOn = ECB_No;
	SphereComponent->SetShouldUpdatePhysicsVolume(true);
	SphereComponent->SetCanEverAffectNavigation(false);
	SphereComponent->bDynamicObstacle = true;
	
	RootComponent = SphereComponent;

	// Adding and attach SpringArm Component
	//CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//CameraBoom->SetupAttachment(RootComponent);

	// Adding and attach Camera to the SpringArm
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);

	// Adding Floating Component so our pawn can move.
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingComponent"));

	// Initialize our Camera settings. Probably is a good idea to functionalise this.
	CameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController)
	{
		PlayerController->Possess(this);
	}
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	BindInputs(PlayerInputComponent);
}

void ACameraPawn::BindInputs(UInputComponent* OwnerInputComponent)
{
	if (!InputDataSetupDataAsset)
	{
		// We don't have the data needed to perform this bindings, bail.
		return;
	}

	// Bind Axes
	if (InputDataSetupDataAsset->ForwardMovement != NAME_None)
	{
		OwnerInputComponent->BindAxis(InputDataSetupDataAsset->ForwardMovement, this, &ACameraPawn::MoveForward);
	}

	if (InputDataSetupDataAsset->LateralMovement != NAME_None)
	{
		OwnerInputComponent->BindAxis(InputDataSetupDataAsset->LateralMovement, this, &ACameraPawn::MoveRight);
	}

	if (InputDataSetupDataAsset->TurnRate != NAME_None)
	{
		OwnerInputComponent->BindAxis(InputDataSetupDataAsset->TurnRate, this, &ACameraPawn::Turn);
	}

	if (InputDataSetupDataAsset->LookUpRate != NAME_None)
	{
		OwnerInputComponent->BindAxis(InputDataSetupDataAsset->LookUpRate, this, &ACameraPawn::LookUp);
	}

	if (InputDataSetupDataAsset->CraneUp != NAME_None)
	{
		OwnerInputComponent->BindAxis(InputDataSetupDataAsset->CraneUp, this, &ACameraPawn::CraneMovement);
	}

	if (InputDataSetupDataAsset->CraneUp != NAME_None)
	{
		OwnerInputComponent->BindAxis(InputDataSetupDataAsset->CraneDown, this, &ACameraPawn::CraneMovement);
	}

	// Bind Actions
	if (InputDataSetupDataAsset->HidePhotoModeUI != NAME_None)
	{
		OwnerInputComponent->BindAction(InputDataSetupDataAsset->HidePhotoModeUI, IE_Released, this, &ACameraPawn::HidePhotoUI);
	}
}

void ACameraPawn::MoveForward(float Scale)
{
	FVector Direction = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::X);
	Direction = FVector(Direction.X, Direction.Y, 0.f).GetSafeNormal();
	AddMovementInput(Direction, Scale);
}

void ACameraPawn::MoveRight(float Scale)
{
	FVector Direction = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y);
	Direction = FVector(Direction.X, Direction.Y, 0.f).GetSafeNormal();
	AddMovementInput(Direction, Scale);
}

void ACameraPawn::Turn(float Scale)
{
	AddControllerYawInput(Scale);
}

void ACameraPawn::LookUp(float Scale)
{
	AddControllerPitchInput(Scale);
}

void ACameraPawn::CraneMovement(float Scale) 
{
	AddMovementInput(this->GetActorUpVector(), Scale);
}

void ACameraPawn::HidePhotoUI()
{
	if (!CameraComponent)
	{
		// We shouldn't hit this. The camera is attached to the actor.
	}
}

