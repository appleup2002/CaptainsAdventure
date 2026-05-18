// Fill out your copyright notice in the Description page of Project Settings.

#include "AC_GameInstance.h"

void UAC_GameInstance::Init()
{
	Super::Init();

	// 游戏启动时加载默认语言（中文）
	UAC_LocalizationMgr::SetLanguage(ELanguage::Chinese);
}
