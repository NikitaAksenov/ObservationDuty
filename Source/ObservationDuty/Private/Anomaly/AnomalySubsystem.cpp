// Fill out your copyright notice in the Description page of Project Settings.


#include "Anomaly/AnomalySubsystem.h"

void UAnomalySubsystem::RegisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent)
{
	AnomalyComponents.Add(InAnomalyComponent);
}

void UAnomalySubsystem::UnregisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent)
{
	AnomalyComponents.Remove(InAnomalyComponent);
}
