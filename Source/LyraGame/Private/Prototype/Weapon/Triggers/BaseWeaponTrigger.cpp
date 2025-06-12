// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Weapon/Triggers/BaseWeaponTrigger.h"

ABaseWeaponTrigger::ABaseWeaponTrigger()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ABaseWeaponTrigger::OnFireStart_Implementation() {}

void ABaseWeaponTrigger::OnFireCancel_Implementation() {}
