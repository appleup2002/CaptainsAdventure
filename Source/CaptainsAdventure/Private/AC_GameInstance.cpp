// Fill out your copyright notice in the Description page of Project Settings.

#include "AC_GameInstance.h"
#include "AC_SaveGame.h"
#include "AC_GameConfigMgr.h"
#include "Kismet/GameplayStatics.h"

void UAC_GameInstance::Init()
{
	Super::Init();

	// 优先从存档加载语言设置，没有存档则使用默认中文
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0))
	{
		UAC_SaveGame* Save = Cast<UAC_SaveGame>(
			UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
		if (Save)
		{
			UAC_LocalizationMgr::SetLanguage(Save->SavedLanguage);
		}
	}
	else
	{
		UAC_LocalizationMgr::SetLanguage(ELanguage::Chinese);
	}

	// 加载数值配置
	UAC_GameConfigMgr::LoadAll();
}

void UAC_GameInstance::SaveGame(const TArray<EAbility>& UnlockedAbilities)
{
	UAC_SaveGame* Save = Cast<UAC_SaveGame>(
		UGameplayStatics::CreateSaveGameObject(UAC_SaveGame::StaticClass()));

	if (!Save) return;

	Save->UnlockedAbilities = UnlockedAbilities;
	Save->SavedLanguage = UAC_LocalizationMgr::GetLanguage();

	UGameplayStatics::SaveGameToSlot(Save, SaveSlotName, 0);
	UE_LOG(LogTemp, Log, TEXT("GameInstance: 游戏已保存"));
}

TArray<EAbility> UAC_GameInstance::GetSavedAbilities() const
{
	if (!UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0))
		return {};

	UAC_SaveGame* Save = Cast<UAC_SaveGame>(
		UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));

	if (!Save) return {};

	UE_LOG(LogTemp, Log, TEXT("GameInstance: 读取能力列表，数量: %d"), Save->UnlockedAbilities.Num());
	return Save->UnlockedAbilities;
}

void UAC_GameInstance::DeleteSave()
{
	UGameplayStatics::DeleteGameInSlot(SaveSlotName, 0);
	UE_LOG(LogTemp, Log, TEXT("GameInstance: 存档已删除"));
}

bool UAC_GameInstance::HasSave() const
{
	return UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0);
}