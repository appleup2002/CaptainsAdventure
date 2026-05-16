// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageMgr.h"
#include "AC_Character.h"

void UDamageMgr::DoApplyDamage(AActor* Instigator, AActor* Receiver, double Amount, EDamageType DamageType)
{
	if (!Receiver) return;

	// 尝试将受击目标转换为角色基类，成功则调用蓝图实现的受伤逻辑
	AAC_Character* Character = Cast<AAC_Character>(Receiver);
	if (Character)
	{
		Character->ReceiveAttack(Amount);
	}
}
