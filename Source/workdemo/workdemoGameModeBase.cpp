// Copyright Epic Games, Inc. All Rights Reserved.


#include "workdemoGameModeBase.h"



AworkdemoGameModeBase::AworkdemoGameModeBase()
{
    DefaultPawnClass = ACharacterPlayerBase::StaticClass();
}

void AworkdemoGameModeBase::BeginPlay()
{
    Super::BeginPlay(); // 调用父类的BeginPlay


    // 设置变量值 - 对应蓝图中的VariableSet节点
    RotationAngle = 0.0f;
    NowDirection = FVector(1.0f, 0.0f, 0.0f); // 对应蓝图中的默认值 "1.000000, 0, 0"
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is a screen message!"));
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(DefaultP/*awnClass.Get()));*/
    }

}