// Fill out your copyright notice in the Description page of Project Settings.

#include "Prototype/Weapon/BFLWeaponUtils.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

TArray<FHitResult> UBFLWeaponUtils::GeneratePredictedTraces(const AActor* WorldContextActor, const int32 Amount, const FRandomStream Stream,
    const ECollisionChannel CollisionChannel, const FVector TraceStart, const FVector TraceDir, const float TraceLength,
    TArray<AActor*> ActorsToIgnore, const float ConeHalfAngle, bool DrawDebug)
{
    TArray<FHitResult> HitResults;

    if (!WorldContextActor) return HitResults;

    for (int32 i = 0; i < Amount; ++i)
    {
        FHitResult HitResult;

        FCollisionQueryParams QueryParams;
        QueryParams.AddIgnoredActors(ActorsToIgnore);

        FVector RandomTraceDir = UKismetMathLibrary::RandomUnitVectorInConeInDegreesFromStream(
            TraceDir, ConeHalfAngle, FRandomStream(Stream.GetCurrentSeed() + i));

        FVector TraceEnd = RandomTraceDir * TraceLength + TraceStart;

        const auto TraceProfile = UCollisionProfile::Get();
        if (!TraceProfile) return HitResults;

        auto TraceType = TraceProfile->ConvertToTraceType(CollisionChannel);

        const auto DebugType = DrawDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None;

        UKismetSystemLibrary::LineTraceSingle(
            WorldContextActor->GetWorld(), TraceStart, TraceEnd, TraceType, false, ActorsToIgnore, DebugType, HitResult, true);

        HitResults.Add(HitResult);
    }

    return HitResults;
}
