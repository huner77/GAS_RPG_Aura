// Copyright huner


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	check(AttributeInfo);

	/*FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfo(FAuraGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);*/

	for (auto& Pair:AS->TagToAttributes)
	{
		FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfo(Pair.Key);
		Info.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(Info);
	}
}

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	
}
