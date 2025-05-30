// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Weapon/Abilities/WeaponHitscanShotAbility.h"
#include "DrawDebugHelpers.h"

void UWeaponHitscanShotAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    const auto World = GetWorld();

    if (!World) return;

    FCollisionQueryParams QueryParams;

    QueryParams.AddIgnoredActor(GetOwnerPawn());

    FHitResult HitResult;

    FVector TraceStart, TraceEnd;

    GetTraceData(TraceStart, TraceEnd);

    World->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, TraceChannel, QueryParams);

    DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 2.0f, -1, 0.5f);

    EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}

bool UWeaponHitscanShotAbility::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
    const auto OwnerPawn = GetOwnerPawn();
    if (!OwnerPawn) return false;

    const auto OwnerController = OwnerPawn->GetController();
    if (!OwnerController) return false;

    FRotator TraceRotation;

    OwnerController->GetPlayerViewPoint(TraceStart, TraceRotation);

    TraceEnd = TraceRotation.Vector() * HitscanDistance + TraceStart;

    return true;
}
