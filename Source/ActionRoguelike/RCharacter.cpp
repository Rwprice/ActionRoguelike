// Fill out your copyright notice in the Description page of Project Settings.


#include "RCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ARCharacter::ARCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ARCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}


// Called every frame
void ARCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ARCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

