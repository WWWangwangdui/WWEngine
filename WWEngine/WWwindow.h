/// <summary>
/// �ļ�����: WWwindow.h
/// ����ʱ�䣺2021/3/27
/// �����ˣ�	����
/// ������ʱ�䣺2021/3/28
/// �ĵ�������������ģ���ͷ�ļ�
/// </summary>
#pragma once
#include<Windows.h>
#include<iostream>
#include"WWdefine.h"
static class WWframe
{
private:
public:
	static WWCH* WWtime;
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static void WWmsgCycle();

#ifdef _DEBUG
public:
	static void createconsole();
	static void debug(const WWCH* file, WWINT line,const WWCH* debuginfo);
#endif// DEBUG

};
class WWwindow
{
private:
	/*
	typedef struct tagWNDCLASSEXW {
	UINT      cbSize;			ʵ����ռ�õ��ڴ��С
	UINT      style;			���ڵ���ʽ
	WNDPROC   lpfnWndProc;		ָ�򴰿ڵĻص�����
	int       cbClsExtra;		���ڵĶ�����Ϣ
	int       cbWndExtra;		����ʵ���Ķ�����Ϣ
	HINSTANCE hInstance;		ʵ�����
	HICON     hIcon;			ͼ�����Դ���		NULLΪĬ��ͼ��
	HCURSOR   hCursor;			�����Դ���
	HBRUSH    hbrBackground;	���ڱ���ˢ
	LPCSTR    lpszMenuName;		�˵�����Դ��
	LPCSTR    lpszClassName;	ָ�򴰿����ָ��
	HICON     hIconSm;			������ͼ����
	} WNDCLASSEXA, *PWNDCLASSEXA, *NPWNDCLASSEXA, *LPWNDCLASSEXA;
	*/
	WNDCLASSEXW WWwnd;
	HWND WWhWnd;
	WWCH WWcursorPath[100];
	WWCH WWtitle[100];
	LONG WWwindowStyle;
	WWINT WWwindowSizeX;
	WWINT WWwindowSizeY;
	WWINT WWwindowPosX;
	WWINT WWwindowPosY;
	WWINT WWscreenSizeX;
	WWINT WWscreenSizeY;
	void WWMoveWindow();
public:
	WWwindow();
	void WWinitWnd(HINSTANCE hInstance);
	void WWshowWnd();
	void WWhideWnd();
	void WWfullScreen();
	void WWwindowScreen();
	void WWsetMaxButton();
	bool WWgetMaxButton();
	void WWremMaxButton();
	void WWsetMinButton();
	bool WWgetMinButton();
	void WWremMinButton();
	HWND WWgetHWnd();
	void WWsetSize(WWINT WWsizeX,WWINT WWsizeY);
	WWINT WWgetSize(WWSEL WWselect);
	void save(FILE* fp);
	void load(FILE* fp);
};