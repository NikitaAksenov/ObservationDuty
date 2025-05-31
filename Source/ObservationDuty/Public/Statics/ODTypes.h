// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"

#include "ODTypes.generated.h"


USTRUCT(BlueprintType, Blueprintable)
struct FRoomTag
{
	GENERATED_BODY()

public:
	FRoomTag() : Tag(FGameplayTag()) {}
	
	explicit FRoomTag(const FGameplayTag& InTag) : Tag(InTag) {}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Tag;

public:
	FString ToString() const;
};
