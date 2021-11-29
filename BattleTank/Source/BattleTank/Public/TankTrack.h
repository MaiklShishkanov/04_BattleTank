// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
		
public:
	//устанавливаем значение для гусеницы между -1 и +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	//это мксимальная сила на гусеницу в Ньютанах
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000;//масса танка 40 тонн и ускорение в 1g
};
