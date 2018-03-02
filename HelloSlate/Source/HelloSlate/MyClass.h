// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Object.h"
#include "MyClass.generated.h"

/**
 * 
 */
UCLASS(config = Game)
class HELLOSLATE_API UMyClass : public UObject
{
	GENERATED_BODY()

	UMyClass();
	~UMyClass();
public:
	static UMyClass* Get();

	FORCEINLINE FString GetUserName() { return UserName; }
	FORCEINLINE FString GetPassword() { return Password; }
	FORCEINLINE void SaveUserName(FString _UserName)
	{
		GConfig->SetString(*FString("AdminInfo"), *FString("UserName"), *_UserName, GGameIni);
	}
	FORCEINLINE void SavePassword(FString _Password)
	{
		GConfig->SetString(*FString("AdminInfo"), *FString("Password"), *_Password, GGameIni);
	}
private:

	UPROPERTY(config)
	FString UserName;
	UPROPERTY(config)
	FString Password;


	static UMyClass* Singleton;
};
