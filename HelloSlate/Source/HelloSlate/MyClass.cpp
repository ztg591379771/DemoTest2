// Fill out your copyright notice in the Description page of Project Settings.
#include "MyClass.h"
#include "Core.h"
UMyClass* UMyClass::Singleton = NULL;

UMyClass::UMyClass()
{
	UserName = "";
	Password = "";
	//获取管理员信息
	GConfig->GetString(TEXT("AdminInfo"), TEXT("UserName"), UserName, GGameIni);
	GConfig->GetString(TEXT("AdminInfo"), TEXT("Password"), Password, GGameIni);

}

//单例模式
UMyClass::~UMyClass()
{
	Singleton = NULL;
}



UMyClass * UMyClass::Get()
{
	if (!Singleton)
	{
		Singleton = NewObject<UMyClass>();
	}
	return Singleton;
}
