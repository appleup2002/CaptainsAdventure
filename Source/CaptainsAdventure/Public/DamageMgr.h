// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DamageMgr.generated.h"

UENUM(BlueprintType)
enum class EDamageType : uint8
{
	Physical	UMETA(DisplayName = "Physical"),
	Magic		UMETA(DisplayName = "Magic"),
	Fire		UMETA(DisplayName = "Fire"),
	Ice			UMETA(DisplayName = "Ice"),
	Pure		UMETA(DisplayName = "True"),
};

USTRUCT(BlueprintType)
struct FDamageInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	AActor* Instigator = nullptr;

	UPROPERTY(BlueprintReadWrite)
	AActor* Receiver = nullptr;

	UPROPERTY(BlueprintReadWrite)
	double Amount = 0.0;

	UPROPERTY(BlueprintReadWrite)
	EDamageType DamageType = EDamageType::Physical;
};

// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageDealt, const FDamageInfo&, DamageInfo);

// 前向声明，避免循环引用
class AAC_Character;

UCLASS()
class CAPTAINSADVENTURE_API UDamageMgr : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Damage")
	static void DoApplyDamage(AActor* Instigator, AActor* Receiver, double Amount, EDamageType DamageType);
};
