// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"

#include "GameplayTagContainer.h"

#include "ODCameraActor.generated.h"


UCLASS()
class OBSERVATIONDUTY_API AODCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	AODCameraActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Settings")
	FGameplayTag RoomTag;

public:
	UFUNCTION(BlueprintCallable, Category = "ObservationDuty|Camera")
	FGameplayTag GetRoomTag() const { return RoomTag; }
};
