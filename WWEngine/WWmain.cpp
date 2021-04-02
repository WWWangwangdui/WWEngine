/// <summary>
/// 文件名称: WWmain.cpp
/// 创建时间：2021/3/27
/// 创建人：	赵霄
/// 最后更新时间：2021/3/28
/// 文档描述：软件入口
/// </summary>
#include"WWdefine.h"
#include"WWrenderer.h"
#include"WWwindow.h"
#include"WWtimer.h"
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
#ifdef _DEBUG
	WWframe::createconsole();
#endif // _DEBUG
	time_t now = time(0);
	tm* tmp = localtime(&now);
	sprintf(WWframe::WWtime, "%d/%d/%d %d:%d:%d", tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday, tmp->tm_hour, tmp->tm_min, tmp->tm_sec);
	WWframe::WWlogPtr = fopen(WWframe::WWlogPath,"a");
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
	if (!SUCCEEDED(CoInitialize(NULL)))
	{
		WWERROR("申请使用COM组件失败");
		WWLOG("程序异常结束,错误信息：");
		WWNEWLINE;
		WWNEWLINE;
		fclose(WWframe::WWlogPtr);
		delete[] WWframe::WWtime;
		return 0;
	}
	WWLOG("程序启动");
	try
	{
		WWwindow wnd;
		wnd.WWinitWnd(hInstance);
		wnd.WWshowWnd();
		wnd.WWremMaxButton();
		wnd.WWremMinButton();
		WWrenderer::WWinit(wnd.WWgetHWnd());
		WWtimer::WWinit(wnd.WWgetHWnd());
		WWframe::WWmsgCycle();
		WWLOG("程序正常结束\n\n");
		delete[] WWframe::WWtime;
		fclose(WWframe::WWlogPtr);
	}
	catch (std::string e)
	{
		WWLOG("程序异常结束,错误信息：");
		WWLOG(e.c_str());
		WWNEWLINE;
		WWNEWLINE;
		fclose(WWframe::WWlogPtr);
		delete[] WWframe::WWtime;
	}
	return 0;
}