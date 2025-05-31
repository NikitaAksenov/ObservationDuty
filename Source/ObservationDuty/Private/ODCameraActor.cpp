// Fill out your copyright notice in the Description page of Project Settings.


#include "ODCameraActor.h"

#include "Kismet/KismetStringLibrary.h"


AODCameraActor::AODCameraActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AODCameraActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AODCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
