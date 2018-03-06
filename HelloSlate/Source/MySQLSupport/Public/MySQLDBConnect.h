#pragma once


#include "mysql.h"
#include "CoreMinimal.h"
class   MySQLDBConnect
{
public:
	void Init();
public:
	MySQLDBConnect();
	~MySQLDBConnect();
	FString version_str;
private:
	MYSQL mysql;

	//是否连接上MySQL
	bool bIsConnetedMySQL;
};