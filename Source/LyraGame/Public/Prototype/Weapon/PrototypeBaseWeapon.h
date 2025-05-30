// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PrototypeBaseWeapon.generated.h"

class UWeaponAbilityComponent;

UCLASS()
class LYRAGAME_API APrototypeBaseWeapon : public AActor
{
    GENERATED_BODY()

public:
    APrototypeBaseWeapon();

    void DefaultAttackStart();
    void DefaultAttackStop();

protected:
    virtual void BeginPlay() override;

    UFUNCTION(Server, Reliable)
    void ServerDefaultAttackStart();
    void ServerDefaultAttackStart_Implementation();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    TObjectPtr<UWeaponAbilityComponent> WeaponAbilityComponent;
};
