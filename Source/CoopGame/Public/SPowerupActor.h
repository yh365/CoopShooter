// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPowerupActor.generated.h"

UCLASS()
class COOPGAME_API ASPowerupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASPowerupActor();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Powerups")
	float PowerupInterval;

	UPROPERTY(EditDefaultsOnly, Category = "Powerups")
	int32 TotalNrOfTicks;

	FTimerHandle TimerHandle_PowerupTick;

	int32 TicksProcessed;

	UFUNCTION()
	void OnTickPowerup();

	UPROPERTY(ReplicatedUsing=OnRep_PowerupActive)
	bool bIsPowerupActive;

	UFUNCTION()
	void OnRep_PowerupActive();

	UFUNCTION(BlueprintImplementableEvent, Category = "Powerups")
	void OnPowerupStateChanged(bool bNewIsActive);

public:	

	void ActivatePowerup(AActor* ActiveFor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Powerups")
	void OnActivated(AActor* ActiveFor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Powerups")
	void OnPowerupTicked();

	UFUNCTION(BlueprintImplementableEvent, Category = "Powerups")
	void OnExpired();
	
};
