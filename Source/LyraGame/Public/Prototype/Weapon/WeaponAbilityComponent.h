// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WeaponAbilityComponent.generated.h"

class UWeaponBaseShotAbility;

UCLASS()
class LYRAGAME_API UWeaponAbilityComponent : public UAbilitySystemComponent
{
    GENERATED_BODY()

public:
    UWeaponAbilityComponent();

    void MakeDefaultShot();

protected:
    virtual void BeginPlay() override;

    void GrandInitialAbilities();

    bool IsServer() const { return GetOwner() && GetOwner()->HasAuthority(); }

    UFUNCTION(Server, Reliable)
    void ServerMakeDefaultShot();
    void ServerMakeDefaultShot_Implementation();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Shot")
    TSubclassOf<UWeaponBaseShotAbility> DefaultShotAbilityClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Shot")
    TSubclassOf<UWeaponBaseShotAbility> AltShotAbilityClass;

    UPROPERTY(BlueprintReadWrite)
    TObjectPtr<UWeaponBaseShotAbility> DefaultShot;

    UPROPERTY(BlueprintReadWrite)
    TObjectPtr<UWeaponBaseShotAbility> AltShot;
};
