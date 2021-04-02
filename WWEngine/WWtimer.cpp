#include"WWtimer.h"
#include"WWwindow.h"
HWND  WWtimer::m_hwnd = NULL;
LARGE_INTEGER WWtimer::timeStart;
LARGE_INTEGER WWtimer::frequency;
WWDB WWtimer::quadpart;
WWDB WWtimer::timeNow;
WWDB WWtimer::deltaTime;
void WWtimer::WWinit(HWND hwnd)
{
	hwnd = m_hwnd;
	//计时器频率
	QueryPerformanceFrequency(&frequency);
	quadpart = (double)frequency.QuadPart;
	//初始时间
	QueryPerformanceCounter(&timeStart);
}
WWDB WWtimer::WWtimeNow() 
{
	return timeNow;
}
WWDB WWtimer::WWgetTime()
{
	QueryPerformanceCounter(&timeStart);
	return timeStart.QuadPart * 1000.0 / quadpart;
}
void WWtimer::WWupdate()
{
	WWDB timeTmp = WWgetTime();
	deltaTime = timeTmp - timeNow;
	timeNow = timeTmp;
	time_t now = time(0);
	tm* tmp = localtime(&now);
	sprintf(WWframe::WWtime, "%d/%d/%d %d:%d:%d", tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday, tmp->tm_hour, tmp->tm_min, tmp->tm_sec);
}
WWDB WWtimer::WWdeltaTime()
{
	return deltaTime;
}

