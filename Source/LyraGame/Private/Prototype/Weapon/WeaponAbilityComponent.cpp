// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Weapon/WeaponAbilityComponent.h"
#include "Prototype/Weapon/Abilities/WeaponBaseShotAbility.h"

UWeaponAbilityComponent::UWeaponAbilityComponent()
{
    SetIsReplicatedByDefault(true);
}

void UWeaponAbilityComponent::MakeDefaultShot()
{
    if (!IsServer())
    {
        ServerMakeDefaultShot();
        return;
    }

    TryActivateAbilityByClass(DefaultShotAbilityClass, true);  
}

void UWeaponAbilityComponent::BeginPlay()
{
    Super::BeginPlay();

    GrandInitialAbilities();
}

void UWeaponAbilityComponent::GrandInitialAbilities()
{
    TArray<TSubclassOf<UWeaponBaseShotAbility>> AbilitiesToGive = {DefaultShotAbilityClass, AltShotAbilityClass};

    if (IsServer())
    {
        if (DefaultShotAbilityClass)
        {
            GiveAbility(FGameplayAbilitySpec(DefaultShotAbilityClass, 1, -1, this));
        }

        if (AltShotAbilityClass)
        {
            GiveAbility(FGameplayAbilitySpec(AltShotAbilityClass, 1, -1, this));
        }
        
    }
}

void UWeaponAbilityComponent::ServerMakeDefaultShot_Implementation()
{
    MakeDefaultShot();
}
