// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeaponTrigger.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFireTriggerDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFireCanceledTriggerDelegate);

UCLASS(Abstract)
class LYRAGAME_API ABaseWeaponTrigger : public AActor
{
    GENERATED_BODY()

public:
    ABaseWeaponTrigger();

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnFireTriggerDelegate OnFireTriggerDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnFireCanceledTriggerDelegate OnFireCanceledTriggerDelegate;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireStart();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireCancel();
};
