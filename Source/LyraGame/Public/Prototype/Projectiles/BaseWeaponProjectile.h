// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeaponProjectile.generated.h"

class UProjectileMovementComponent;
class UBoxComponent;

UCLASS()
class LYRAGAME_API ABaseWeaponProjectile : public AActor
{
    GENERATED_BODY()

public:
    ABaseWeaponProjectile();

    UFUNCTION(BlueprintCallable)
    void SetShotDirection(const FVector& NewDirection) { ShotDirection = NewDirection; }

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_ShotDirectionQuanitized();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    TObjectPtr<UBoxComponent> CollisionComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    TObjectPtr<UStaticMeshComponent> ProjectileMesh;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

    UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
    FVector ShotDirection;

    UPROPERTY(ReplicatedUsing = OnRep_ShotDirectionQuanitized, BlueprintReadWrite)
    FVector_NetQuantize100 ShotDirectionQuanitized;
};
