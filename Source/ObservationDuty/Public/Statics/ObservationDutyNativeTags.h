// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "NativeGameplayTags.h"


#define UE_OD_DECLARE_GAMEPLAY_TAG(TagName) OBSERVATIONDUTY_API extern FNativeGameplayTag TagName;
#define UE_OD_DEFINE_GAMEPLAY_TAG(TagName, Tag, Comment) FNativeGameplayTag TagName("", UE_MODULE_NAME, Tag, Comment, ENativeGameplayTagToken::PRIVATE_USE_MACRO_INSTEAD);

UE_OD_DECLARE_GAMEPLAY_TAG(TAG_OD_Room)