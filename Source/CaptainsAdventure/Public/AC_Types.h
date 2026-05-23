// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AC_Types.generated.h"

// 角色能力枚举，与蓝图中 E_Abilities 对应
UENUM(BlueprintType)
enum class EAbility : uint8
{
	DoubleJump	UMETA(DisplayName = "Double Jump"),
	ThrowSword	UMETA(DisplayName = "Throw Sword"),
};
