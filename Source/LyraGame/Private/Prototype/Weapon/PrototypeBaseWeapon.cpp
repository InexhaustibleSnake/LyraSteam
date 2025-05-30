// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Weapon/PrototypeBaseWeapon.h"
#include "Prototype/Weapon/WeaponAbilityComponent.h"

APrototypeBaseWeapon::APrototypeBaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;

	WeaponAbilityComponent = CreateDefaultSubobject<UWeaponAbilityComponent>("WeaponAbilityComponent");
}

void APrototypeBaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}


