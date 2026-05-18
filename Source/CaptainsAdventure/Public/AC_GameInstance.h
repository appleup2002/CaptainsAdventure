// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AC_LocalizationMgr.h"
#include "AC_GameInstance.generated.h"

UCLASS()
class CAPTAINSADVENTURE_API UAC_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// 游戏启动时初始化，加载默认语言
	virtual void Init() override;
};
