// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPickupActor.generated.h"

class USphereComponent;
class UDecalComponent;
class ASPowerupActor;
class USoundBase;

UCLASS()
class COOPGAME_API ASPickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASPickupActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UDecalComponent* DecalComp;

	UPROPERTY(EditInstanceOnly, Category = "PickupActor")
	TSubclassOf<ASPowerupActor> PowerUpClass;

	ASPowerupActor* PowerUpInstance;

	UPROPERTY(EditInstanceOnly, Category = "PickupActor")
	float CooldownDuration;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundBase* PickupSound;

	FTimerHandle TimerHandle_RespawnTimer;

	void Respawn();

public:	

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};
