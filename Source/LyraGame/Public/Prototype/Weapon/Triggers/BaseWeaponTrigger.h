// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeaponTrigger.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFireTriggerDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFireEndedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFireCanceledTriggerDelegate);

UCLASS(Abstract)
class LYRAGAME_API ABaseWeaponTrigger : public AActor
{
    GENERATED_BODY()

public:
    ABaseWeaponTrigger();

    UFUNCTION(BlueprintCallable)
    bool GetEndAbilityOnFire() const { return EndAbilityOnFire; }

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnFireTriggerDelegate OnFireTrigger;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnFireEndedDelegate OnFireEnded;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnFireCanceledTriggerDelegate OnFireCanceled;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireStart();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireInputReleased();

    protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool EndAbilityOnFire = false;
};
