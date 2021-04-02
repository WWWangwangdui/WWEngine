#include "WWmoduleBase.h"

void WWmoduleBase::WWsetModuleActivity(WWSEL sel)
{
	WWactivity = sel;
}

WWINT WWmoduleBase::WWgetModuleID()
{
	return WWmoduleID;
}

std::string& WWmoduleBase::WWgetModuleName()
{
	return WWmoduleName;
}

WWBOOL WWmoduleBase::WWfindModule(std::string modulename)
{
	if ((this)->WWgetModuleName() == modulename)
	{
		return true;
	}
	return false;
}

