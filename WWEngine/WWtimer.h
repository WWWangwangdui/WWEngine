#pragma once
#include"WWtype.h"
static class WWtimer 
{
private:
	//窗口句柄
	static HWND m_hwnd;      		
	//计时辅助变量
	static LARGE_INTEGER timeStart;
	//时钟频率
	static LARGE_INTEGER frequency;
	//当前程序运行时间
	static WWDB timeNow;
	//帧时间差
	static WWDB deltaTime;
	static WWDB quadpart;
public:										  
	static void WWinit(HWND hwnd);	
	//获得系统运行时间
	static WWDB WWdeltaTime();
	static WWDB WWtimeNow();
	static WWDB WWgetTime();
	static void WWupdate();
};