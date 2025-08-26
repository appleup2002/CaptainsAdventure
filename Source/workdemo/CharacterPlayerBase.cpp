// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayerBase.h"

using This = ACharacterPlayerBase;

This::ACharacterPlayerBase() {
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArm);

	CameraComp->bUsePawnControlRotation = false;

	AttackAnim = LoadObject<UPaperZDAnimSequence>(
		nullptr,
		TEXT("/Game/BluePrints/Characters/Player/Captain/AnimSequences/Attack.Attack")
	);
	AttackDelay = 1.0f;



}

void This::BeginPlay() {
	Super::BeginPlay();
	//0 is Player
	Fraction = 0;

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, TEXT("We are using CharacterPlayerBase."));
	
}

void ACharacterPlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("Move_Y", this, &ACharacterPlayerBase::Move_Y);
	PlayerInputComponent->BindAxis("Move_X", this, &ACharacterPlayerBase::Move_X);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &This::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &This::EndJump);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &This::StartAttack);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &This::EndAttack);
	PlayerInputComponent->BindAction("RotateRight", IE_Pressed, this, &This::StartRotateRight);
	PlayerInputComponent->BindAction("RotateRight", IE_Released, this, &This::EndRotateRight);
	PlayerInputComponent->BindAction("RotateLeft", IE_Pressed, this, &This::StartRotateLeft);
	PlayerInputComponent->BindAction("RotateLeft", IE_Released, this, &This::EndRotateLeft);

}

void This::StartJump() {
	bPressedJump = true;
	//Jump();
}
void This::EndJump() {
	bPressedJump = false;
}

void ACharacterPlayerBase::Move_Y(float value) {
	AddMovementInput({ 0, 1, 0 }, value);
}
void ACharacterPlayerBase::Move_X(float value) {
	AddMovementInput({ 1, 0, 0 }, value);
}

void This::StartAttack() {

	if (!CanAct())
		return;

	IsAttack = true;

	GetAnimInstance()->PlayAnimationOverride(
		AttackAnim,
		"AttackSlot",
		1.0f,
		0.0f
	);

	GetWorld()->GetTimerManager().SetTimer(
		AttackTimer,
		this,
		&This::OnAttackAnimationCompleted,
		1.0,
		false,
		0.5f
	);
}
void This::OnAttackAnimationCompleted() {
	IsAttack = false;
}
void This::EndAttack() {}

void This::StartRotateLeft() {}
void This::EndRotateLeft() {}

void This::StartRotateRight() {}
void This::EndRotateRight() {}