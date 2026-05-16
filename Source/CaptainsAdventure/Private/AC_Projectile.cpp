// Fill out your copyright notice in the Description page of Project Settings.

#include "AC_Projectile.h"

AAC_Projectile::AAC_Projectile()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAC_Projectile::SetProjectileInstigator(AActor* InInstigator)
{
	ProjectileInstigator = InInstigator;
}

void AAC_Projectile::BeginPlay()
{
	Super::BeginPlay();
}

void AAC_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
