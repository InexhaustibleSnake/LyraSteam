// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PrototypeCharacter.generated.h"

class APrototypeBaseWeapon;

UCLASS()
class LYRAGAME_API APrototypeCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    APrototypeCharacter();

    UFUNCTION(BlueprintCallable)
    APrototypeBaseWeapon* GetCurrentWeapon() const { return CurrentWeapon; }

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Amount);
    void MoveRight(float Amount);
    void MouseX(float Amount);
    void MouseY(float Amount);

    void Shoot();
    void AltShot();

    UPROPERTY()
    APrototypeBaseWeapon* CurrentWeapon;
};
