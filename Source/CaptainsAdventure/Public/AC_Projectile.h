// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AC_Projectile.generated.h"

UCLASS()
class CAPTAINSADVENTURE_API AAC_Projectile : public AActor
{
	GENERATED_BODY()

public:
	AAC_Projectile();

	// 投掷物的发射者，由生成方在 Spawn 后调用 SetProjectileInstigator 设置
	UPROPERTY(BlueprintReadOnly, Category = "Projectile")
	AActor* ProjectileInstigator = nullptr;

	// 设置发射者，蓝图和 C++ 均可调用
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SetProjectileInstigator(AActor* InInstigator);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
