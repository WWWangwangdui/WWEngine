#pragma once
#include"WWtype.h"
static class WWtimer 
{
private:
	//���ھ��
	static HWND m_hwnd;      		
	//��ʱ��������
	static LARGE_INTEGER timeStart;
	//ʱ��Ƶ��
	static LARGE_INTEGER frequency;
	//��ǰ��������ʱ��
	static WWDB timeNow;
	//֡ʱ���
	static WWDB deltaTime;
	static WWDB quadpart;
public:										  
	static void WWinit(HWND hwnd);	
	//���ϵͳ����ʱ��
	static WWDB WWdeltaTime();
	static WWDB WWtimeNow();
	static WWDB WWgetTime();
	static void WWupdate();
};