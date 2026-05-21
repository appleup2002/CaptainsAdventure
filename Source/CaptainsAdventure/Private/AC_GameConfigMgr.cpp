// Fill out your copyright notice in the Description page of Project Settings.

#include "AC_GameConfigMgr.h"

// ini 中的节名
static const TCHAR* ConfigSection = TEXT("PlayerConfig");

// 当前玩家配置，默认值由结构体成员初始化提供
static FPlayerConfigData PlayerConfig;

void UAC_GameConfigMgr::LoadAll()
{
	if (!GConfig) return;

	// 逐键读取，读取失败时保留结构体默认值并输出警告
	if (!GConfig->GetFloat(ConfigSection, TEXT("MaxHealth"), PlayerConfig.MaxHealth, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: MaxHealth 读取失败，使用默认值 %.1f"), PlayerConfig.MaxHealth);

	if (!GConfig->GetFloat(ConfigSection, TEXT("MoveSpeed"), PlayerConfig.MoveSpeed, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: MoveSpeed 读取失败，使用默认值 %.1f"), PlayerConfig.MoveSpeed);

	if (!GConfig->GetFloat(ConfigSection, TEXT("BaseDamage"), PlayerConfig.BaseDamage, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: BaseDamage 读取失败，使用默认值 %.1f"), PlayerConfig.BaseDamage);

	if (!GConfig->GetFloat(ConfigSection, TEXT("DamageCoeff"), PlayerConfig.DamageCoeff, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: DamageCoeff 读取失败，使用默认值 %.1f"), PlayerConfig.DamageCoeff);

	if (!GConfig->GetInt(ConfigSection, TEXT("MaxJumpCount"), PlayerConfig.MaxJumpCount, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: MaxJumpCount 读取失败，使用默认值 %d"), PlayerConfig.MaxJumpCount);

	UE_LOG(LogTemp, Log, TEXT("GameConfigMgr: 配置加载完成"));
}

void UAC_GameConfigMgr::HotReload()
{
	if (!GConfig) return;

	// 重新解析 ini 文件，PIE 运行中即可生效
	GConfig->LoadFile(GGameIni);
	LoadAll();

	UE_LOG(LogTemp, Log, TEXT("GameConfigMgr: 热加载完成"));
}

FPlayerConfigData UAC_GameConfigMgr::GetPlayerConfig()
{
	return PlayerConfig;
}
