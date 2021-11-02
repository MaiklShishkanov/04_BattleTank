// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Contr not Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Contr: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()){ return; }

	FVector HitLocation;//внешний параметр
	if (GetSightRayHitLocation(HitLocation)) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 VieportSizeX, VieportSizeY;
	GetViewportSize(VieportSizeX, VieportSizeY);
	auto ScreenLocation = FVector2D(VieportSizeX * CrossHairXLocation, VieportSizeY * CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());

	return true;
}