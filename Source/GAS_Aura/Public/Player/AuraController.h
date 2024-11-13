// Copyright  huner

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraController.generated.h"



class UInputMappingContext;


/**
 * 
 */
UCLASS()
class GAS_AURA_API AAuraController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraController();
protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<UInputMappingContext> AuraContext;
};
