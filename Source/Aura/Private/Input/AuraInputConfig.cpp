// Copyright huner


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	bool bLogNotFound) const
{
	for (auto& InputAction : AbilityInputActions)
	{
		if (InputAction.InputAction && InputTag.MatchesTag(InputAction.InputTag))
		{
			return InputAction.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find AbilityInputAction for %s, on InputConfig[%s]"), *InputTag.ToString(),*GetNameSafe(this));
	}

	return nullptr;
}
