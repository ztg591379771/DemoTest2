#pragma once

#include "mysql.h"
#include "CoreMinimal.h"



class MYSQLSUPPORT_API  MySQLDBConnect
{
public:
	void Init();
public:
	void findSQL();


	MySQLDBConnect();
	~MySQLDBConnect();
	FString version_str;
private:
	MYSQL mysql;
	
	//�Ƿ�������MySQL
	bool bIsConnetedMySQL;
};