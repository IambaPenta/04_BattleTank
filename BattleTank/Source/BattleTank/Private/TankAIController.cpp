// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();
	auto PlayerControlledTank = GetPlayerTank();

	if (!AIControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController currently not possessing a tank."))
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController now possessing %s"), *AIControlledTank->GetName());
	}

	if (!PlayerControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Where the fuck is the player?!"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("I found %s"), *PlayerControlledTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetPlayerTank()) 
	{
		// TODO Move towards the player
		// Aim at the player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
	
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}

