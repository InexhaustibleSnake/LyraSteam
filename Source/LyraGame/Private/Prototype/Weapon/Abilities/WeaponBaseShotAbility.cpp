// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Weapon/Abilities/WeaponBaseShotAbility.h"

UWeaponBaseShotAbility::UWeaponBaseShotAbility() 
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

APawn* UWeaponBaseShotAbility::GetOwnerPawn() const
{
    const AActor* OwnerWeaponActor = Cast<AActor>(GetOuter());
    if (!OwnerWeaponActor) return nullptr;

    return Cast<APawn>(OwnerWeaponActor->GetOwner());
}
