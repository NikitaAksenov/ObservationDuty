// Fill out your copyright notice in the Description page of Project Settings.


#include "Anomaly/AnomalyComponent.h"


UAnomalyComponent::UAnomalyComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UAnomalyComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UAnomalyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
