// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"

using This = ACharacterBase;

ACharacterBase::ACharacterBase() 
{
	PrimaryActorTick.bCanEverTick = true;

	AttackCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Attack_Collision"));
	AttackCollision->SetupAttachment(RootComponent);

	AttackCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	AttackCollision->SetGenerateOverlapEvents(true);
	AttackCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AttackCollision->OnComponentBeginOverlap.AddDynamic(this, &This::OnBoxBeginOverlap);
	//AttackCollision->OnComponentEndOverlap.AddDynamic(this, &This::OnBoxEndOverlap);
}

void ACharacterBase::BeginPlay() {
	Super::BeginPlay();
	IsStun = false;
	IsAttack = false;
	IsDefeated = false;
	ShakeFlag = true;
	MaxHealth = 100.0f;
	Health = MaxHealth;
	AttackDamage = 20;

	//check(GEngine != nullptr);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, TEXT("We are using CharacterBase."));
	//SetDefaultPawn
}

bool This::CanAct() {
	return (!IsAttack) && (!IsStun) && !(IsStun);
}

void This::EnableAttackCollision(bool Active) {

	if (Active) {
		AttackCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	else {
		AttackCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	}
}

void This::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if (OtherActor == this)
		return; // 直接退出，避免自己攻击自己
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("AttackDamage"));
	This* overlapped = dynamic_cast<This*>(OtherActor);

	
	if (!overlapped)	return;

	if (overlapped->Fraction != Fraction) {
		overlapped->RecieveAttack(AttackDamage);
	}
}
//void This::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
//	return;
//}

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
	//GetAnimInstance()->StopAllAnimationOverrides();

	if (Health > 0) {
		IsStun = true;
		Stuned.Broadcast(true);
		
		GetAnimInstance()->JumpToNode(TEXT("Stun_Jump"));

		GetWorld()->GetTimerManager().SetTimer(StunTimer, this, &This::ClearStun, 1.0f, false, 0.5f);

		GetWorld()->GetTimerManager().SetTimer(StunShakeTimer, this, &This::ShakeSelf, 1.0f, true, 0.055f);

	}
	else {
		IsDefeated = true;
		GetAnimInstance()->JumpToNode(TEXT("DefeatJump"));
		}
}

void This::ShakeSelf() {
	FVector SpriteRLoc = GetSprite()->GetRelativeLocation();
	float ShakePower = 5;
	if (ShakeFlag) ShakePower = -ShakePower;
	ShakeFlag = !ShakeFlag;

	SpriteRLoc.X += ShakePower;

	GetSprite()->SetRelativeLocation(SpriteRLoc, false);
}

void This::ClearStun() {
	IsStun = false;

	Stuned.Broadcast(false);

}