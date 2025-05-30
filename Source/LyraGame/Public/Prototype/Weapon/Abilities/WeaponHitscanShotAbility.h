// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Prototype/Weapon/Abilities/WeaponBaseShotAbility.h"
#include "WeaponHitscanShotAbility.generated.h"

UCLASS()
class LYRAGAME_API UWeaponHitscanShotAbility : public UWeaponBaseShotAbility
{
    GENERATED_BODY()

protected:
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);
    
    bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;
      
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Hitscan")
    float HitscanDistance = 10000.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Hitscan")
    TEnumAsByte<ECollisionChannel> TraceChannel = ECollisionChannel::ECC_Visibility;
};
