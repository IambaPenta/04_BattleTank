// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();
	if (!AIControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController currently not possessing a tank."))
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController now possessing %s"), *AIControlledTank->GetName());
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

