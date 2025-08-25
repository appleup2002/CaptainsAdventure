// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CharacterPlayerBase.h"
#include "workdemoGameModeBase.generated.h"
/**
 * 
 */
UCLASS()
class WORKDEMO_API AworkdemoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AworkdemoGameModeBase();

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Custom")
	float RotationAngle;

	UPROPERTY(BlueprintReadWrite, Category = "Custom")
	FVector NowDirection;

private:
	virtual void BeginPlay() override;

};
