// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "BFLWeaponUtils.generated.h"

UCLASS(Blueprintable)
class LYRAGAME_API UBFLWeaponUtils : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable,BlueprintPure, Category = "Weapon Utils")
    static TArray<FHitResult> GeneratePredictedTraces(const AActor* WorldContextActor, const int32 Amount, const FRandomStream Stream,
        const ECollisionChannel CollisionChannel, const FVector TraceStart, const FVector TraceDir, const float TraceLength,
        TArray<AActor*> ActorsToIgnore, const float ConeHalfAngle, bool DrawDebug = false);
};
