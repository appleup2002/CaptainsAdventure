// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_MainPlay.h"
using ASelf = AGM_MainPlay;


ASelf::AGM_MainPlay()
{
	RotationAngle = 0.0f; // FMath::RadiansToDegrees(0) 结果就是 0
	NowDirection = FVector::ZeroVector; // FVector(0.0f, 0.0f, 0.0f) 可以简写为 FVector::ZeroVector
}

void ASelf::BeginPlay()
{
}