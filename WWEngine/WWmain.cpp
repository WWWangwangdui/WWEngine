/// <summary>
/// �ļ�����: WWmain.cpp
/// ����ʱ�䣺2021/3/27
/// �����ˣ�	����
/// ������ʱ�䣺2021/3/28
/// �ĵ�������������
/// </summary>
#include"WWwindow.h"
#include<iostream>
WWCH* WWframe::WWtime = new WWCH[100];
const WWCH* WWframe::WWlogPath = "log.txt";
FILE* WWframe::WWlogPtr;
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
#ifdef _DEBUG
	WWframe::createconsole();
	time_t now = time(0);
	tm* tmp = localtime(&now);
#endif // _DEBUG
	sprintf(WWframe::WWtime, "%d/%d/%d %d:%d:%d", tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday, tmp->tm_hour, tmp->tm_min, tmp->tm_sec);
	WWframe::WWlogPtr = fopen(WWframe::WWlogPath, "ab");
	WWLOG("��������");
	try
	{
		WWwindow wnd;
		wnd.WWinitWnd(hInstance);
		wnd.WWshowWnd();
		wnd.WWremMaxButton();
		wnd.WWremMinButton();
		//wnd.WWfullScreen();
		WWframe::WWmsgCycle();
		//WWLOG("������������\n\n");
		delete[] WWframe::WWtime;
		fclose(WWframe::WWlogPtr);
	}
	catch (std::string e)
	{
		WWLOG("�����쳣����,������Ϣ��");
		WWLOG(e.c_str());
		WWNEWLINE;
		WWNEWLINE;
		fclose(WWframe::WWlogPtr);
		delete[] WWframe::WWtime;
	}
	return 0;
}