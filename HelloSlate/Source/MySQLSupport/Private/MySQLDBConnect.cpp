
#include "MySQLSupport.h"
#include "MySQLDBConnect.h"

void MySQLDBConnect::Init()
{
	mysql_init(&mysql);
	//mysql_real_connect(&mysql, TCHAR_TO_ANSI(*DBAddress), TCHAR_TO_ANSI(*DecodeUserName), "passworddb", TCHAR_TO_ANSI(*DecodeDBName), Port, NULL, 0)
	//mysql_real_connect(conn, "127.0.0.1", "root", "123456", "test", 3306, NULL, 0);
	if (mysql_real_connect(&mysql,"127.0.0.1","root","123456","mytest",3306,NULL,0)==NULL)
	{
		bIsConnetedMySQL = false;
		mysql_close(&mysql);
		return;
	}
	bIsConnetedMySQL = true;
	version_str = FString::FormatAsNumber(mysql_get_server_version(&mysql));
	mysql_set_character_set(&mysql, "utf8");
}

MySQLDBConnect::MySQLDBConnect()
{
	version_str = "Œ¥’“µΩ";
	Init();
	
}

MySQLDBConnect::~MySQLDBConnect()
{
}
