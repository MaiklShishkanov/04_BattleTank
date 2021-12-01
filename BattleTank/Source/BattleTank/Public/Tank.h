// Mikhail V

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//��������������� ���������� Forward Diclaration
class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

protected:
	// Called when the game starts or when spawned
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LounchSpeed = 4000; // ��������� �������� �������

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3; //����� ����������� ����� ���������� AI

	UTankBarrel* Barrel = nullptr; //��������� ������ �� ����� ��� ���������� ��������
	double LastFireTime = 0;
};
