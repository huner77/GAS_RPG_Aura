// Copyright huner


#include "UI/WidgetController/OverlayAuraWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayAuraWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayAuraWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	/*AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayAuraWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayAuraWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayAuraWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayAuraWidgetController::MaxManaChanged);*/

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetHealthAttribute()).AddLambda(
	[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
AuraAttributeSet->GetMaxHealthAttribute()).AddLambda(
[this](const FOnAttributeChangeData& Data)
	{
		OnMaxHealthChanged.Broadcast(Data.NewValue);
	}
);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
AuraAttributeSet->GetManaAttribute()).AddLambda(
[this](const FOnAttributeChangeData& Data)
	{
		OnManaChanged.Broadcast(Data.NewValue);
	}
);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
AuraAttributeSet->GetMaxManaAttribute()).AddLambda(
[this](const FOnAttributeChangeData& Data)
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
);


	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTages)
		{
			for (const FGameplayTag& Tag : AssetTages)
			{
			//	const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
			//	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Blue, Msg);
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					FUIWidgetRow* Row= GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowSignature.Broadcast(*Row);
				}
				
			}
		}
	);
	
}

/*void UOverlayAuraWidgetController::HealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue);

}

void UOverlayAuraWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	OnMaxMaxHealthChanged.Broadcast(Data.NewValue);

}

void UOverlayAuraWidgetController::ManaChanged(const FOnAttributeChangeData& Data)
{
	OnManaChanged.Broadcast(Data.NewValue);

}

void UOverlayAuraWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data)
{
	OnMaxManaChanged.Broadcast(Data.NewValue);

}*/