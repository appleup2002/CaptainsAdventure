// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "CharacterMonsterBase.generated.h"

/**
 * 
 */
UCLASS()
class WORKDEMO_API ACharacterMonsterBase : public ACharacterBase
{
	GENERATED_BODY()

public:
	ACharacterMonsterBase();
	void BeginPlay();
	
};

