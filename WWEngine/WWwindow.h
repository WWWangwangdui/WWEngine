/// <summary>
/// 文件名称: WWwindow.h
/// 创建时间：2021/3/27
/// 创建人：	赵霄
/// 最后更新时间：2021/3/28
/// 文档描述：主窗体模块的头文件
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
	UINT      cbSize;			实例所占用的内存大小
	UINT      style;			窗口的样式
	WNDPROC   lpfnWndProc;		指向窗口的回调函数
	int       cbClsExtra;		窗口的额外信息
	int       cbWndExtra;		窗口实例的额外信息
	HINSTANCE hInstance;		实例句柄
	HICON     hIcon;			图标的资源句柄		NULL为默认图标
	HCURSOR   hCursor;			鼠标资源句柄
	HBRUSH    hbrBackground;	窗口背景刷
	LPCSTR    lpszMenuName;		菜单的资源名
	LPCSTR    lpszClassName;	指向窗口类的指针
	HICON     hIconSm;			任务栏图标句柄
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