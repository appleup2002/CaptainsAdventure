// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"

using This = ACharacterBase;

ACharacterBase::ACharacterBase() 
{
	PrimaryActorTick.bCanEverTick = true;

	AttackCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Attack_Collision"));
	AttackCollision->SetupAttachment(RootComponent);

	EnableAttackCollision(false);

	AttackCollision->OnComponentBeginOverlap.AddDynamic(this, &This::OnBoxBeginOverlap);
	AttackCollision->OnComponentBeginOverlap.AddDynamic(this, &This::OnBoxBeginOverlap);
}

void ACharacterBase::BeginPlay() {
	Super::BeginPlay();
	IsStun = false;
	IsAttack = false;
	IsDefeated = false;
	MaxHealth = 100.0f;
	Health = MaxHealth;
	AttackDamage = 20;

	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, TEXT("We are using CharacterBase."));
	//SetDefaultPawn
}

bool This::CanAct() {
	return (!IsAttack) && (!IsStun) && !(IsStun);
}

void This::EnableAttackCollision(bool Active) {

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, TEXT("Change Active"));


	if (Active) {
		AttackCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	else {
		AttackCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void This::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult) {
	//dynamic_cast<>
}
void This::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void This::RecieveAttack(float damage) {

	if (!HitSound) {
		UE_LOG(LogTemp, Display, TEXT("HitSound is null"));
		return;
	}
	UGameplayStatics::PlaySoundAtLocation(this,HitSound,GetActorLocation(),
		1.0f, 1.0f, 0.0f,nullptr,nullptr);
	
	if (IsDefeated)
		return;
	Health = Health - damage;
	GetAnimInstance()->StopAllAnimationOverrides();

	if (Health > 0) {
		Stuned.Broadcast(true);
		
		GetAnimInstance()->JumpToNode(TEXT("Stun_Jump"));

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &This::ClearStun, 1.0f, false, 0.5f);
	}
	
}

void This::ClearStun() {
	IsStun = false;
}