// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "AnomalySubsystem.generated.h"


class UAnomalyComponent;


/**
 * 
 */
UCLASS()
class OBSERVATIONDUTY_API UAnomalySubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()


protected:
	TSet<UAnomalyComponent*> AnomalyComponents;

public:
	void RegisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent);
	void UnregisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent);
};
