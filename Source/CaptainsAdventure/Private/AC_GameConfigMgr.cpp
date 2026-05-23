// Fill out your copyright notice in the Description page of Project Settings.

#include "AC_GameConfigMgr.h"

static const TCHAR* PlayerSection  = TEXT("PlayerConfig");
static const TCHAR* MonsterSection = TEXT("MonsterConfig");

static FPlayerConfigData  PlayerConfig;
static FMonsterConfigData MonsterConfig;
static FSharkConfigData   SharkConfig;

void UAC_GameConfigMgr::LoadAll()
{
	if (!GConfig) return;

	// 逐键读取，读取失败时保留结构体默认值并输出警告
	// ── 玩家配置 ──
	if (!GConfig->GetFloat(PlayerSection, TEXT("MaxHealth"), PlayerConfig.MaxHealth, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: MaxHealth 读取失败，使用默认值 %.1f"), PlayerConfig.MaxHealth);

	if (!GConfig->GetFloat(PlayerSection, TEXT("MoveSpeed"), PlayerConfig.MoveSpeed, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: MoveSpeed 读取失败，使用默认值 %.1f"), PlayerConfig.MoveSpeed);

	if (!GConfig->GetFloat(PlayerSection, TEXT("BaseDamage"), PlayerConfig.BaseDamage, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: BaseDamage 读取失败，使用默认值 %.1f"), PlayerConfig.BaseDamage);

	if (!GConfig->GetFloat(PlayerSection, TEXT("DamageCoeff"), PlayerConfig.DamageCoeff, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: DamageCoeff 读取失败，使用默认值 %.1f"), PlayerConfig.DamageCoeff);

	if (!GConfig->GetInt(PlayerSection, TEXT("MaxJumpCount"), PlayerConfig.MaxJumpCount, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: MaxJumpCount 读取失败，使用默认值 %d"), PlayerConfig.MaxJumpCount);

	// ── 通用怪物配置 ──
	if (!GConfig->GetFloat(MonsterSection, TEXT("HealDropRate"), MonsterConfig.HealDropRate, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: HealDropRate 读取失败，使用默认值 %.2f"), MonsterConfig.HealDropRate);

	// ── 鲨鱼配置 ──
	static const TCHAR* SharkSection = TEXT("SharkConfig");
	if (!GConfig->GetFloat(SharkSection, TEXT("MaxHealth"), SharkConfig.MaxHealth, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: Shark.MaxHealth 读取失败，使用默认值 %.1f"), SharkConfig.MaxHealth);

	if (!GConfig->GetFloat(SharkSection, TEXT("MoveSpeed"), SharkConfig.MoveSpeed, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: Shark.MoveSpeed 读取失败，使用默认值 %.1f"), SharkConfig.MoveSpeed);

	if (!GConfig->GetFloat(SharkSection, TEXT("BaseDamage"), SharkConfig.BaseDamage, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: Shark.BaseDamage 读取失败，使用默认值 %.1f"), SharkConfig.BaseDamage);

	if (!GConfig->GetFloat(SharkSection, TEXT("DamageCoeff"), SharkConfig.DamageCoeff, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: Shark.DamageCoeff 读取失败，使用默认值 %.1f"), SharkConfig.DamageCoeff);

	if (!GConfig->GetFloat(SharkSection, TEXT("AttackRadius"), SharkConfig.AttackRadius, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: Shark.AttackRadius 读取失败，使用默认值 %.1f"), SharkConfig.AttackRadius);

	if (!GConfig->GetFloat(SharkSection, TEXT("HealDropRate"), SharkConfig.HealDropRate, GGameIni))
		UE_LOG(LogTemp, Warning, TEXT("GameConfigMgr: Shark.HealDropRate 读取失败，使用默认值 %.2f"), SharkConfig.HealDropRate);

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

FMonsterConfigData UAC_GameConfigMgr::GetMonsterConfig()
{
	return MonsterConfig;
}

FSharkConfigData UAC_GameConfigMgr::GetSharkConfig()
{
	return SharkConfig;
}
