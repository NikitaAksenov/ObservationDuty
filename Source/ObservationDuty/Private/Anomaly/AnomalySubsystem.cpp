// Fill out your copyright notice in the Description page of Project Settings.


#include "Anomaly/AnomalySubsystem.h"

#include "Anomaly/AnomalyComponent.h"


DEFINE_LOG_CATEGORY(LogAnomalySubsystem);


TStatId UAnomalySubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UAnomalySubsystem, STATGROUP_Tickables);
}

void UAnomalySubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogAnomalySubsystem, Log, TEXT("Anomalies:"));
	int Index = 1;
	for (UAnomalyComponent* AnomalyComponent : AllAnomalies)
	{
		UE_LOG(LogAnomalySubsystem, Log, TEXT(" - #%d %s %s"),
			Index, *AnomalyComponent->GetOwner()->GetName(), AnomalyComponent->IsAnomalyActive() ? TEXT("Active") : TEXT("Inactive"));
		Index++;
	}

	UE_LOG(LogAnomalySubsystem, Log, TEXT("Anomalies by room:"));
	for (auto& AnomaliesInRoom : AllAnomaliesByRoom)
	{
		UE_LOG(LogAnomalySubsystem, Log, TEXT(" - Room: %s"), *AnomaliesInRoom.Key.ToString());
		Index = 1;
		for (UAnomalyComponent* AnomalyComponent : AnomaliesInRoom.Value)
		{
			UE_LOG(LogAnomalySubsystem, Log, TEXT(" - - #%d %s %s"),
				Index, *AnomalyComponent->GetOwner()->GetName(), AnomalyComponent->IsAnomalyActive() ? TEXT("Active") : TEXT("Inactive"));
			Index++;
		}
	}
}

void UAnomalySubsystem::RegisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent)
{
	check(InAnomalyComponent && InAnomalyComponent->GetRoomTag().IsValid());

	UE_LOG(LogAnomalySubsystem, Log, TEXT("Register anomaly component of %s"), *InAnomalyComponent->GetOwner()->GetName());
	
	AllAnomalies.Add(InAnomalyComponent);

	AllAnomaliesByRoom.FindOrAdd(InAnomalyComponent->GetRoomTag()).Add(InAnomalyComponent);
}

void UAnomalySubsystem::UnregisterAnomalyComponent(UAnomalyComponent* InAnomalyComponent)
{
	check(InAnomalyComponent && InAnomalyComponent->GetRoomTag().IsValid());
	
	UE_LOG(LogAnomalySubsystem, Log, TEXT("Unregister anomaly component of %s"), *InAnomalyComponent->GetOwner()->GetName());

	AllAnomalies.Remove(InAnomalyComponent);

	if (TSet<UAnomalyComponent*>* Anomalies = AllAnomaliesByRoom.Find(InAnomalyComponent->GetRoomTag()))
	{
		Anomalies->Remove(InAnomalyComponent);
	}
}
