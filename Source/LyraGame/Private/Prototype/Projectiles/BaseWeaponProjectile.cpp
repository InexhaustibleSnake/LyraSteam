// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Projectiles/BaseWeaponProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/BoxComponent.h"
#include "Net/UnrealNetwork.h"

ABaseWeaponProjectile::ABaseWeaponProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>("CollisionComponent");
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
    ProjectileMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    ProjectileMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    ProjectileMesh->SetGenerateOverlapEvents(false);
    ProjectileMesh->SetupAttachment(GetRootComponent());
 
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");

	ProjectileMovementComponent->InitialSpeed = 1500.0f;

	bReplicates = true;
}

void ABaseWeaponProjectile::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority())
    {
        ShotDirectionQuanitized = ShotDirection;
        OnRep_ShotDirectionQuanitized();
    }


}

void ABaseWeaponProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const 
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ABaseWeaponProjectile, ShotDirectionQuanitized)
}

void ABaseWeaponProjectile::OnRep_ShotDirectionQuanitized() 
{
    if (!ProjectileMovementComponent) return;

    ProjectileMovementComponent->Velocity = ShotDirectionQuanitized * ProjectileMovementComponent->InitialSpeed;
}
