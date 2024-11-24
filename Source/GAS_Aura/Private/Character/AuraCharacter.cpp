// Copyright  huner


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	// 使角色的朝向自动根据其移动方向调整，即角色会面向其移动的方向
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// 设置角色旋转速率，指定每秒旋转的角度为400度（仅限于Yaw方向）
	GetCharacterMovement()->RotationRate = FRotator(0, 400.f, 0);

	// 约束角色在一个平面上移动，通常用于2D游戏或特定的轴向限制
	GetCharacterMovement()->bConstrainToPlane = true;

	// 在游戏开始时，让角色的位置自动调整到平面上（如果角色不在平面上）
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// 禁止角色根据控制器的Pitch（俯仰）旋转，这样角色不会因为控制器的俯仰变化而倾斜
	bUseControllerRotationPitch = false;

	// 禁止角色根据控制器的Yaw（偏航）旋转，这样角色不会因为控制器的偏航变化而旋转
	bUseControllerRotationYaw = false;

	// 禁止角色根据控制器的Roll（滚动）旋转，这样角色不会因为控制器的滚动变化而翻转
	bUseControllerRotationRoll = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState =	GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}
