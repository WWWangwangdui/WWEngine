#include "WWasCtrl.h"

void WWasCtrl::WWinit()
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

WWSOUND& WWasCtrl::WWgetSound(WWINT WWid)
{
	return WWerrorSound;
}

WWBIT WWasCtrl::WWgetBit(WWINT WWid)
{
	return WWBIT();
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
