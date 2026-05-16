// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "AC_Character.generated.h"

UCLASS()
class CAPTAINSADVENTURE_API AAC_Character : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	// 受到攻击时由蓝图实现（扣血、播放动画等），参数与蓝图保持一致
	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
	void ReceiveAttack(double Damage);
};
