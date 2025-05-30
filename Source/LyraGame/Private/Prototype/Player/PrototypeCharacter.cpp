// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Player/PrototypeCharacter.h"

APrototypeCharacter::APrototypeCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APrototypeCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APrototypeCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APrototypeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (!PlayerInputComponent) return;

    PlayerInputComponent->BindAxis("MoveForward", this, &APrototypeCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APrototypeCharacter::MoveRight);

    PlayerInputComponent->BindAxis("MouseX", this, &APrototypeCharacter::MouseX);
    PlayerInputComponent->BindAxis("MouseY", this, &APrototypeCharacter::MouseY);

    PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &APrototypeCharacter::Shoot);
    PlayerInputComponent->BindAction("AltShot", IE_Pressed, this, &APrototypeCharacter::AltShot);
}

void APrototypeCharacter::MoveForward(float Amount) 
{
    AddMovementInput(GetActorForwardVector(), Amount);
}

void APrototypeCharacter::MoveRight(float Amount) 
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void APrototypeCharacter::MouseX(float Amount) 
{
    AddControllerYawInput(Amount);
}

void APrototypeCharacter::MouseY(float Amount) 
{
    AddControllerPitchInput(Amount);
}

void APrototypeCharacter::Shoot() {}

void APrototypeCharacter::AltShot() {}
