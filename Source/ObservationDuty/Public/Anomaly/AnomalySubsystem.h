// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "GameplayTagContainer.h"

#include "AnomalySubsystem.generated.h"


class UAnomalyComponent;


DECLARE_LOG_CATEGORY_EXTERN(LogAnomalySubsystem, Log, All);


/**
 * 
 */
UCLASS()
class OBSERVATIONDUTY_API UAnomalySubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()


public:
	//~ Start UTickableWorldSubsystem Interface
	virtual TStatId GetStatId() const override;
	virtual void Tick(float DeltaTime) override;
	//~ End UTickableWorldSubsystem Interface

protected:
	TSet<UAnomalyComponent*> AnomalyComponents;
	
	TMap<FGameplayTag, TSet<UAnomalyComponent*>> AnomaliesByRoom;

public:
	void RegisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent);
	void UnregisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent);
};
