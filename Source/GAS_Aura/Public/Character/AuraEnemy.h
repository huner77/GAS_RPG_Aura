// Copyright  huner

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class GAS_AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	AAuraEnemy();

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
};
