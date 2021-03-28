/// <summary>
/// 文件名称: WWmain.cpp
/// 创建时间：2021/3/27
/// 创建人：	赵霄
/// 最后更新时间：2021/3/28
/// 文档描述：软件入口
/// </summary>
#include"WWwindow.h"
#include<iostream>
WWCH* WWframe::WWtime = new WWCH[100];
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
#ifdef _DEBUG
	WWframe::createconsole();
	time_t now = time(0);
	tm* tmp = localtime(&now);
	sprintf(WWframe::WWtime, "%d:%d:%d", tmp->tm_hour, tmp->tm_min, tmp->tm_sec);
#endif // _DEBUG

	WWwindow wnd;
	wnd.WWinitWnd(hInstance);
	wnd.WWshowWnd();
	//wnd.WWfullScreen();
	WWframe::WWmsgCycle();
	return 0;
}