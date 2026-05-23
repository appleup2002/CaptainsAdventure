// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AC_GameConfigMgr.generated.h"

// 玩家配置数据结构体，成员默认值在缺失配置时兜底
USTRUCT(BlueprintType)
struct FPlayerConfigData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	float MaxHealth = 100.f;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeed = 600.f;

	UPROPERTY(BlueprintReadOnly)
	float BaseDamage = 10.f;

	UPROPERTY(BlueprintReadOnly)
	float DamageCoeff = 1.f;

	UPROPERTY(BlueprintReadOnly)
	int32 MaxJumpCount = 1;
};

// 通用怪物配置（掉落等全局怪物设置）
USTRUCT(BlueprintType)
struct FMonsterConfigData
{
	GENERATED_BODY()

	// 掉落回血道具的概率，0.0~1.0，默认30%
	UPROPERTY(BlueprintReadOnly)
	float HealDropRate = 0.3f;
};

// 鲨鱼怪配置
USTRUCT(BlueprintType)
struct FSharkConfigData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	float MaxHealth = 150.f;

	UPROPERTY(BlueprintReadOnly)
	float MoveSpeed = 400.f;

	UPROPERTY(BlueprintReadOnly)
	float BaseDamage = 15.f;

	UPROPERTY(BlueprintReadOnly)
	float DamageCoeff = 1.f;

	// 攻击范围半径
	UPROPERTY(BlueprintReadOnly)
	float AttackRadius = 75.f;

	// 掉落回血道具的概率（覆盖全局设置）
	UPROPERTY(BlueprintReadOnly)
	float HealDropRate = 0.3f;
};

UCLASS()
class CAPTAINSADVENTURE_API UAC_GameConfigMgr : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// 从 DefaultGame.ini 读取所有配置节
	UFUNCTION(BlueprintCallable, Category = "Config")
	static void LoadAll();

	// 热加载：重新解析 .ini 文件，PIE 运行中即可生效
	UFUNCTION(BlueprintCallable, Category = "Config")
	static void HotReload();

	// 获取玩家配置
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	static FPlayerConfigData GetPlayerConfig();

	// 获取通用怪物配置
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	static FMonsterConfigData GetMonsterConfig();

	// 获取鲨鱼怪配置
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	static FSharkConfigData GetSharkConfig();
};
