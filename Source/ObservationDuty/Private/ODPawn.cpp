// Fill out your copyright notice in the Description page of Project Settings.


#include "ODPawn.h"

#include "ODCameraActor.h"
#include "ODGameModeBase.h"
#include "Kismet/GameplayStatics.h"


AODPawn::AODPawn()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AODPawn::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AODCameraActor::StaticClass(), CameraActors);
	for (AActor* CameraActor : CameraActors)
	{
		if (AODCameraActor* Camera = Cast<AODCameraActor>(CameraActor))
		{
			Cameras.Add(Camera);
		}
	}
	check(!Cameras.IsEmpty());

	SelectCamera(0);
}

void AODPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AODPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AODPawn::SelectCamera(int InCameraIndex)
{
	check(Cameras.IsValidIndex(InCameraIndex));

	AODCameraActor* NewCamera = Cameras[InCameraIndex];

	if (CurrentCamera == NewCamera)
	{
		return;
	}

	CurrentCamera = NewCamera;
	CurrentCameraIndex = InCameraIndex;

	check(CurrentCamera);

	GetLocalViewingPlayerController()->SetViewTarget(CurrentCamera);
}

void AODPawn::SelectNextCamera()
{
	if (CurrentCameraIndex < Cameras.Num() - 1)
	{
		CurrentCameraIndex++;
	}
	else
	{
		CurrentCameraIndex = 0;
	}

	SelectCamera(CurrentCameraIndex);
}

void AODPawn::SelectPrevCamera()
{
	if (CurrentCameraIndex > 0)
	{
		CurrentCameraIndex--;
	}
	else
	{
		CurrentCameraIndex = Cameras.Num() - 1;
	}
	
	SelectCamera(CurrentCameraIndex);
}
