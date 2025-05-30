// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Weapon/PrototypeBaseWeapon.h"
#include "Prototype/Weapon/WeaponAbilityComponent.h"

APrototypeBaseWeapon::APrototypeBaseWeapon()
{
    PrimaryActorTick.bCanEverTick = false;

    bReplicates = true;

    WeaponAbilityComponent = CreateDefaultSubobject<UWeaponAbilityComponent>("WeaponAbilityComponent");
    WeaponAbilityComponent->SetIsReplicated(true);
}

void APrototypeBaseWeapon::DefaultAttackStart()
{
    if (!HasAuthority())
    {
        ServerDefaultAttackStart();
        return;
    }

    if (!WeaponAbilityComponent) return;

    WeaponAbilityComponent->MakeDefaultShot();
}

void APrototypeBaseWeapon::BeginPlay()
{
    Super::BeginPlay();

    if (WeaponAbilityComponent)
    {
        WeaponAbilityComponent->InitAbilityActorInfo(this, this);
    }
}

void APrototypeBaseWeapon::ServerDefaultAttackStart_Implementation()
{
    DefaultAttackStart();
}
