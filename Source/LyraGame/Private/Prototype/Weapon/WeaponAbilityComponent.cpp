// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Weapon/WeaponAbilityComponent.h"
#include "Prototype/Weapon/Abilities/WeaponBaseShotAbility.h"
#include "Net/UnrealNetwork.h"

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

void UWeaponAbilityComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const 
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION(UWeaponAbilityComponent, Ammo, COND_OwnerOnly);
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
