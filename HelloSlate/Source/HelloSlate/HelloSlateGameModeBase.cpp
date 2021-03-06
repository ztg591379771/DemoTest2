// Fill out your copyright notice in the Description page of Project Settings.

#include "HelloSlateGameModeBase.h"
#include "Engine.h"
#include "MySQLDBConnect.h"
// ++ Include Our HUD header
#include "StandardHUD.h"

void AHelloSlateGameModeBase::BeginPlay()
{
	MySQLDBConnect conn;
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor(255, 0, 0), FString(TEXT("当前正在使用的mysql版本为")) +conn.version_str);
}

// ++ In the constructor, call parent constructor and set the hud class to use our custom HUD by default.
AHelloSlateGameModeBase::AHelloSlateGameModeBase() : Super()
{
	HUDClass = AStandardHUD::StaticClass();
}

