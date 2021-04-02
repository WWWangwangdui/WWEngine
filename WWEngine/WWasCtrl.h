#pragma once
#include"WWtype.h"
static class WWasCtrl
{
private:
	static std::map<std::string, WWmoduleBase*>WWmodulemap;
	static std::map<WWINT, WWSTR>WWstrMap;
	static std::map<WWINT, WWBIT>WWbitMap;
	static std::map<WWINT, WWSOUND*>WWsoundMap;
	static WWSTR WWerrorStr;
	static WWBIT WWerrorBit;
	static WWSOUND* WWerrorSound;
	static WWINT WWnextID;
public:
	static void init();
	static void WWflashID();
	static void WWloatFiles(WWCH* WWpath);
	static void WWsaveFiles(WWCH* WWpath);
	static void WWmakePakage(WWCH* WWpath);
	static void WWreadPakage(WWCH* WWpath);
	static WWSTR& WWgetStr(WWINT WWid);
	static WWSOUND* WWgetSound(WWINT WWid);
	static WWBIT WWgetBit(WWINT WWid);
	static WWmoduleBase* WWgetModule(std::string name);
	static void WWclearMem();
	static void WWaddAsset(WWCH* WWpath, WWINT WWid, WWSEL WWtype);
	static void WWremoveAsset(WWINT WWid);
};

