#pragma once
#include"WWtype.h"
static class WWdirector
{
private:
	static WWINT WWlastID;
	static std::vector<WWobject*>WWobjVec;
	static std::priority_queue<WWINT, std::vector<WWINT>, std::greater<WWINT>> WWdelVec;
public:
	static WWINT WWaddObj();
	static void WWdeleteObj(WWINT id);
	static void WWsave();
	static void WWload();
	static void WWupdate();
	static void WWuiUpdate();
	static void WWinit();
	static WWobject* WWfindObj(const WWCH* name);
	static WWmoduleBase* WWfindModule(const WWCH* name);
};

