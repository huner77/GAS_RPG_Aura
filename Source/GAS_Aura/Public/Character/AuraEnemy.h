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

	/** Enemy Interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end Enemy Interface*/
	
	AAuraEnemy();

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

protected:
	virtual void BeginPlay() override;	
};
