// Fill out your copyright notice in the Description page of Project Settings.


#include "Statics/ODTypes.h"

#include "Kismet/KismetStringLibrary.h"


FString FRoomTag::ToString() const
{
	if (!Tag.IsValid())
	{
		return FString();
	}

	const FString RoomTagString = Tag.ToString();
	const TArray<FString> RoomTagTokens = UKismetStringLibrary::ParseIntoArray(RoomTagString, FString(L"."));

	if (RoomTagTokens.IsEmpty())
	{
		return FString();
	}

	return RoomTagTokens.Last();
}
