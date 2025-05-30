// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GameplayTagContainer.h"

#include "AnomalyComponent.generated.h"


class UAnomalySubsystem;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnomalyEvent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBSERVATIONDUTY_API UAnomalyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAnomalyComponent();

protected:
	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;
	virtual void EndPlay();

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FGameplayTag RoomTag;

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Runtime")
	bool bAnomalyActive = false;

protected:
	UPROPERTY(Transient)
	UAnomalySubsystem* AnomalySubsystem = nullptr;

public:
	UPROPERTY(BlueprintAssignable, Category = "Anomaly")
	FAnomalyEvent OnAnomalyActivatedEvent;

	UPROPERTY(BlueprintAssignable, Category = "Anomaly")
	FAnomalyEvent OnAnomalyDeactivatedEvent;

public:
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Anomaly")
	bool IsAnomalyActive() const { return bAnomalyActive; }
	
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Anomaly")
	void ActivateAnomaly();

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Anomaly")
	void DeactivateAnomaly();
	
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Anomaly")
	FGameplayTag GetRoomTag() const { return RoomTag; }

protected:
	void OnAnomalyActivated();
	void OnAnomalyDeactivated();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Anomaly", DisplayName = "OnAnomalyActivated")
	void K2_OnAnomalyActivated();

	UFUNCTION(BlueprintImplementableEvent, Category = "Anomaly", DisplayName = "OnAnomalyActivated")
	void K2_OnAnomalyDeactivated();
};
