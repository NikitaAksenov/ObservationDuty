// Fill out your copyright notice in the Description page of Project Settings.


#include "Anomaly/AnomalySubsystem.h"


TStatId UAnomalySubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UAnomalySubsystem, STATGROUP_Tickables);
}

void UAnomalySubsystem::RegisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent)
{
	AnomalyComponents.Add(InAnomalyComponent);
}

void UAnomalySubsystem::UnregisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent)
{
	AnomalyComponents.Remove(InAnomalyComponent);
}
