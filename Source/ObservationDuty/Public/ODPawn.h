// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "GameplayTagContainer.h"

#include "ODPawn.generated.h"


class AODCameraActor;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRoomChangedEvent, FGameplayTag, PrevRoomTag, FGameplayTag, CurrRoomTag);


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

	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = "Runtime")
	FGameplayTag CurrentRoomTag;

	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = "Runtime")
	FString CurrentRoomString;

protected:
	void SelectCamera(int InCameraIndex);

public:
	UPROPERTY(BlueprintAssignable, Category = "ObservationDuty")
	FOnRoomChangedEvent OnRoomChangedEvent;

public:
	UFUNCTION(BlueprintCallable, Category = "ObservationDuty")
	void SelectNextCamera();

	UFUNCTION(BlueprintCallable, Category = "ObservationDuty")
	void SelectPrevCamera();

	UFUNCTION(BlueprintCallable, Category = "ObservationDuty")
	FGameplayTag GetCurrentRoomTag() const { return CurrentRoomTag; }

	UFUNCTION(BlueprintCallable, Category = "ObservationDuty")
	FString GetCurrentRoomString() const { return CurrentRoomString; }
	
};
