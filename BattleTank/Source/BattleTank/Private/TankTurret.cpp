// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//MOve the turret the right amount this frame
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto TurretRotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto TurretRotation = RelativeRotation.Yaw + TurretRotationChange;
	SetRelativeRotation(FRotator(0, TurretRotation, 0));
}
