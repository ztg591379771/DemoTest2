// Fill out your copyright notice in the Description page of Project Settings.
#include "MyClass.h"
#include "Core.h"
UMyClass* UMyClass::Singleton = NULL;

UMyClass::UMyClass()
{
	UserName = "";
	Password = "";
	//��ȡ����Ա��Ϣ
	GConfig->GetString(TEXT("AdminInfo"), TEXT("UserName"), UserName, GGameIni);
	GConfig->GetString(TEXT("AdminInfo"), TEXT("Password"), Password, GGameIni);

}

//����ģʽ
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
