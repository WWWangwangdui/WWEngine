#include "WWasCtrl.h"
std::map<std::string, WWmoduleBase*>WWasCtrl::WWmodulemap;
std::map<WWINT, WWSTR>WWasCtrl::WWstrMap;
std::map<WWINT, WWBIT>WWasCtrl::WWbitMap;
std::map<WWINT, WWSOUND*>WWasCtrl::WWsoundMap;
WWSTR WWasCtrl::WWerrorStr;
WWBIT WWasCtrl::WWerrorBit;
WWSOUND* WWasCtrl::WWerrorSound;
WWINT WWasCtrl::WWnextID;
void WWasCtrl::init()
{
}

void WWasCtrl::WWflashID()
{
}

void WWasCtrl::WWloatFiles(WWCH* WWpath)
{
}

void WWasCtrl::WWsaveFiles(WWCH* WWpath)
{
}

void WWasCtrl::WWmakePakage(WWCH* WWpath)
{
}

void WWasCtrl::WWreadPakage(WWCH* WWpath)
{
}

WWSTR& WWasCtrl::WWgetStr(WWINT WWid)
{
	return WWerrorStr;
}

WWSOUND* WWasCtrl::WWgetSound(WWINT WWid)
{
	return WWerrorSound;
}

WWBIT WWasCtrl::WWgetBit(WWINT WWid)
{
	return WWBIT();
}

WWmoduleBase* WWasCtrl::WWgetModule(std::string name)
{
	return nullptr;
}


void WWasCtrl::WWclearMem()
{
}

void WWasCtrl::WWaddAsset(WWCH* WWpath, WWINT WWid, WWSEL WWtype)
{
}

void WWasCtrl::WWremoveAsset(WWINT WWid)
{
}
