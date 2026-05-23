// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AC_LocalizationMgr.h"
#include "AC_Types.h"
#include "AC_GameInstance.generated.h"

// 存档槽名称
static const FString SaveSlotName = TEXT("MainSave");

UCLASS()
class CAPTAINSADVENTURE_API UAC_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	// 保存游戏（拾取能力后、切换语言后调用）
	UFUNCTION(BlueprintCallable, Category = "Save")
	void SaveGame(const TArray<EAbility>& UnlockedAbilities);

	// 读取已解锁的能力列表，存档不存在时返回空数组
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Save")
	TArray<EAbility> GetSavedAbilities() const;

	// 删除存档（重置游戏时调用）
	UFUNCTION(BlueprintCallable, Category = "Save")
	void DeleteSave();

	// 判断存档是否存在
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Save")
	bool HasSave() const;
};