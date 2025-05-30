// Fill out your copyright notice in the Description page of Project Settings.


#include "Anomaly/AnomalyComponent.h"

#include "Anomaly/AnomalySubsystem.h"


UAnomalyComponent::UAnomalyComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UAnomalyComponent::InitializeComponent()
{
	Super::InitializeComponent();

	
}

void UAnomalyComponent::BeginPlay()
{
	Super::BeginPlay();

	AnomalySubsystem = GetWorld()->GetSubsystem<UAnomalySubsystem>();
	check(AnomalySubsystem);

	AnomalySubsystem->RegisterAnomalyComponent(this);
}

void UAnomalyComponent::EndPlay()
{
	AnomalySubsystem->UnregisterAnomalyComponent(this);
}

void UAnomalyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UAnomalyComponent::ActivateAnomaly()
{
	if (!bAnomalyActive)
	{
		bAnomalyActive = true;
		OnAnomalyActivated();
	}
}

void UAnomalyComponent::DeactivateAnomaly()
{
	if (bAnomalyActive)
	{
		bAnomalyActive = false;
		OnAnomalyDeactivated();
	}
}

void UAnomalyComponent::OnAnomalyActivated()
{
	OnAnomalyActivatedEvent.Broadcast();

	K2_OnAnomalyActivated();
}

void UAnomalyComponent::OnAnomalyDeactivated()
{
	OnAnomalyDeactivatedEvent.Broadcast();

	K2_OnAnomalyDeactivated();
}
