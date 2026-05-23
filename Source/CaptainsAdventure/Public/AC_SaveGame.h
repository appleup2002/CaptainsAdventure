// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AC_LocalizationMgr.h"
#include "AC_Types.h"
#include "AC_SaveGame.generated.h"

UCLASS()
class CAPTAINSADVENTURE_API UAC_SaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	// 已解锁的能力列表
	UPROPERTY(BlueprintReadWrite)
	TArray<EAbility> UnlockedAbilities;

	// 存档时的语言设置
	UPROPERTY(BlueprintReadWrite)
	ELanguage SavedLanguage = ELanguage::Chinese;
};