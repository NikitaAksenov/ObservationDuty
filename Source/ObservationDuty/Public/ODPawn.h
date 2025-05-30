// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "ODPawn.generated.h"


class AODCameraActor;

UCLASS()
class OBSERVATIONDUTY_API AODPawn : public APawn
{
	GENERATED_BODY()

public:
	AODPawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
protected:
	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = "Runtime")
	TArray<AODCameraActor*> Cameras;

	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = "Runtime")
	AODCameraActor* CurrentCamera = nullptr;

	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = "Runtime")
	int CurrentCameraIndex = 0;

protected:
	void SelectCamera(int InCameraIndex);

public:
	UFUNCTION(BlueprintCallable)
	void SelectNextCamera();

	UFUNCTION(BlueprintCallable)
	void SelectPrevCamera();
};
