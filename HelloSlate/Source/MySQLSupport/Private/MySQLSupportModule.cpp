
#include "MySQLSupport.h"
#include "MySQLDBConnect.h"

class FMySQLSupportModule
	: public IModuleInterface
{
public:

	// IModuleInterface interface

	virtual void StartupModule() override
	{
	}
	virtual void ShutdownModule() override
	{
	}
};

IMPLEMENT_GAME_MODULE(FMySQLSupportModule, MySQLSupport);