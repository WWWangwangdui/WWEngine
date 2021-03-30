#include "WWmoduleBase.h"

void WWmoduleBase::SetModuleActivity(WWSEL sel)
{
	WWactivity = sel;
}

WWINT WWmoduleBase::getMoudulceID()
{
	return WWmoduleID;
}
