// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Components\BoxComponent.h"
#include "PaperZDAnimationComponent.h"
#include "Kismet/GameplayStatics.h" // 用于GameplayStatics类
#include "Sound/SoundBase.h"        // 用于SoundBase类型
#include "Engine/World.h"           // 用于获取世界上下文
#include "PaperZDAnimInstance.h"
#include "PaperFlipbookComponent.h"
#include "PaperCharacter.h"
#include "Delegates/Delegate.h"       // 委托相关头文件（UE4需显式包含，UE5可省略）
//#include "GameEnum.h"

#include "CharacterBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStuned, bool, bStuned);

UCLASS()
class WORKDEMO_API ACharacterBase : public APaperZDCharacter
{
	GENERATED_BODY()
public:
	ACharacterBase();
	UFUNCTION(BlueprintCallable)
	void EnableAttackCollision(bool Active);
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* AttackCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsStun;
	bool IsAttack;
	bool IsDefeated;
	bool ShakeFlag;
	float MaxHealth;
	float Health;
	float AttackDamage;
	FTimerHandle StunTimer;
	FTimerHandle StunShakeTimer;

	UPROPERTY(EditAnywhere)
	int Fraction;

	//UPROPERTY(BlueprintAssignable, Category = "Stun|Delegate")
	FOnStuned Stuned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* HitSound;

	virtual void BeginPlay();

	virtual bool CanAct();

	UFUNCTION()
	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	//UFUNCTION()
	//virtual void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void RecieveAttack(float damage);

	void ShakeSelf();

	UFUNCTION(BlueprintCallable)
	void ClearStun();
};
