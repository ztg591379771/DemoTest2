// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HelloSlateGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HELLOSLATE_API AHelloSlateGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	// ++ Add a constructor
	AHelloSlateGameModeBase();
	
	
};
