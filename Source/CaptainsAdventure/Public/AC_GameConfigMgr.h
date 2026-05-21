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

UCLASS()
class CAPTAINSADVENTURE_API UAC_GameConfigMgr : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// 从 DefaultGame.ini [PlayerConfig] 节读取所有配置
	UFUNCTION(BlueprintCallable, Category = "Config")
	static void LoadAll();

	// 热加载：重新解析 .ini 文件，PIE 运行中即可生效
	UFUNCTION(BlueprintCallable, Category = "Config")
	static void HotReload();

	// 获取当前玩家配置
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Config")
	static FPlayerConfigData GetPlayerConfig();
};
