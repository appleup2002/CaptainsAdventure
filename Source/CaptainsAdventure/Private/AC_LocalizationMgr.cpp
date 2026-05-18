// Fill out your copyright notice in the Description page of Project Settings.

#include "AC_LocalizationMgr.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// 当前语言，默认中文
static ELanguage CurrentLanguage = ELanguage::Chinese;

// 当前语言的 KV 数据
static TMap<FString, FString> LocalizationData;

void UAC_LocalizationMgr::SetLanguage(ELanguage Language)
{
	CurrentLanguage = Language;
	LoadLanguageFile(Language);
}

ELanguage UAC_LocalizationMgr::GetLanguage()
{
	return CurrentLanguage;
}

FText UAC_LocalizationMgr::GetText(const FString& Key)
{
	const FString* Value = LocalizationData.Find(Key);
	// 找不到 Key 时直接返回 Key 字符串，方便定位缺失翻译
	return FText::FromString(Value ? *Value : Key);
}

void UAC_LocalizationMgr::LoadLanguageFile(ELanguage Language)
{
	// 根据语言选择文件名
	FString FileName;
	switch (Language)
	{
	case ELanguage::English:
		FileName = TEXT("en.lang");
		break;
	default:
		FileName = TEXT("zh_CN.lang");
		break;
	}

	FString FilePath = FPaths::ProjectContentDir() / TEXT("Localization") / FileName;

	TArray<FString> Lines;
	if (!FFileHelper::LoadFileToStringArray(Lines, *FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("LocalizationMgr: 无法加载语言文件 %s"), *FilePath);
		return;
	}

	LocalizationData.Empty();

	for (const FString& Line : Lines)
	{
		// 跳过空行和 # 开头的注释行
		if (Line.IsEmpty() || Line.StartsWith(TEXT("#"))) continue;

		FString Key, Value;
		// 以第一个 = 为分隔符解析 KV
		if (Line.Split(TEXT("="), &Key, &Value))
		{
			LocalizationData.Add(Key.TrimStartAndEnd(), Value.TrimStartAndEnd());
		}
	}

	UE_LOG(LogTemp, Log, TEXT("LocalizationMgr: 已加载 %d 条文本 (%s)"), LocalizationData.Num(), *FileName);
}
