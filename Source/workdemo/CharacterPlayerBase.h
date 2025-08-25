// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PaperZDAnimationComponent.h"
#include "PaperZDAnimInstance.h"
#include "PaperZD\Public\AnimSequences\PaperZDAnimSequence.h"
#include "PaperZDPlaySlotOverrideAction.h"

#include "CharacterPlayerBase.generated.h"

UCLASS()
class WORKDEMO_API ACharacterPlayerBase : public ACharacterBase
{
	GENERATED_BODY()


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* CameraComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Anims")
	UPaperZDAnimSequence* AttackAnim;
	FTimerHandle TimerHandle;

	float AttackDelay;



	ACharacterPlayerBase();

	void BeginPlay();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move_Y(float Value);
	UFUNCTION()
	void Move_X(float Value);

	UFUNCTION()
	void StartJump();
	UFUNCTION()
	void EndJump();

	UFUNCTION()
	void StartAttack();
	UFUNCTION()
	void OnAttackAnimationCompleted();
	UFUNCTION()
	void EndAttack();

	UFUNCTION()
	void StartRotateLeft();
	UFUNCTION()
	void EndRotateLeft();

	UFUNCTION()
	void StartRotateRight();
	UFUNCTION()
	void EndRotateRight();

};
