// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"

#include "Statics/ODTypes.h"

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
	FRoomTag RoomTag;

public:
	UFUNCTION(BlueprintCallable, Category = "ObservationDuty|Camera")
	FRoomTag GetRoomTag() const { return RoomTag; }
};
