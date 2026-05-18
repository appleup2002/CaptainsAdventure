// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AC_LocalizationMgr.generated.h"

UENUM(BlueprintType)
enum class ELanguage : uint8
{
	Chinese		UMETA(DisplayName = "中文"),
	English		UMETA(DisplayName = "English"),
};

UCLASS()
class CAPTAINSADVENTURE_API UAC_LocalizationMgr : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// 切换语言并加载对应 .lang 文件
	UFUNCTION(BlueprintCallable, Category = "Localization")
	static void SetLanguage(ELanguage Language);

	// 获取当前语言
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Localization")
	static ELanguage GetLanguage();

	// 根据 Key 获取当前语言的文本，找不到时返回 Key 本身便于调试
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Localization")
	static FText GetText(const FString& Key);

private:
	// 解析 .lang 文件，填充 LocalizationData
	static void LoadLanguageFile(ELanguage Language);
};
