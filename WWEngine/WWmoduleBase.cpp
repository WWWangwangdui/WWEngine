#include "WWmoduleBase.h"

void WWmoduleBase::WWsetModuleActivity(WWSEL sel)
{
	WWactivity = sel;
}

WWINT WWmoduleBase::WWgetModulcID()
{
	return WWmoduleID;
}

WWSTR WWmoduleBase::WWgetModuleName()
{
	return WWmoduleName;
}

WWBOOL WWmoduleBase::WWfindModule(WWSTR modulename)
{
	if ((this)->WWgetModuleName() == modulename)
	{
		return true;
	}
	return false;
}

