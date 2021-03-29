/// <summary>
/// 文件名称: WWwindow.h
/// 创建时间：2021/3/27
/// 创建人：	赵霄
/// 最后更新时间：2021/3/29
/// 文档描述：主窗体模块的头文件
/// </summary>
#pragma once
#include<Windows.h>
#include<iostream>
#include<atlbase.h>
#include<atlstr.h>
#include"WWdefine.h"
/// <summary>
/// WWframe类为提供主窗体框架的静态类，其功能主要包含窗体的回调函数、窗体的消息循环
/// 在_DEBUG模式下，该类还会提供用于调试的控制台以及debug信息和error信息的打印
/// </summary>
static class WWframe
{
private:
public:
	// 静态字符串，存放时间，该时间仅供debug和error函数，由游戏导演模块进行维护
	static WWCH* WWtime;
	// 静态字符串，存放程序日志的路径
	static const WWCH* WWlogPath;
	// 静态文件指针，指向日志文件
	static FILE* WWlogPtr;
	/// <summary>
	/// 窗体的回调函数
	/// </summary>
	/// <param name="hWnd">收到消息的窗体的句柄</param>
	/// <param name="uMsg">消息的编号</param>
	/// <param name="wParam">16位参数</param>
	/// <param name="lParam">32位参数</param>
	/// <returns></returns>
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	/// <summary>
	/// 消息循环
	/// </summary>
	static void WWmsgCycle();
	/// <summary>
	/// 书写程序日志
	/// </summary>
	/// <param name="file">代码所在文件名</param>
	/// <param name="line">代码所在行数</param>
	/// <param name="debuginfo">日志信息</param>
	static void WWlog(const WWCH* file, WWINT line, const WWCH* loginfo);
	/// <summary>
	/// 在日志文件中换一个空行
	/// </summary>
	static void WWlogNewLine();
#ifdef _DEBUG
public:
	/// <summary>
	/// 创建调试控制台
	/// </summary>
	static void createconsole();
	/// <summary>
	/// 输出调试信息
	/// </summary>
	/// <param name="file">文件路径</param>
	/// <param name="line">代码行数</param>
	/// <param name="debuginfo">调试信息</param>
	static void debug(const WWCH* file, WWINT line,const WWCH* debuginfo);
	/// <summary>
	/// 输出错误信息
	/// </summary>
	/// <param name="file">文件路径</param>
	/// <param name="line">代码行数</param>
	/// <param name="errorinfo">错误信息</param>
	static void error(const WWCH* file, WWINT line, const WWCH* errorinfo);
#endif// DEBUG

};

/// <summary>
/// WWwindow类是对主窗体进行的一系列封装，通过类的实例化可以轻松实现窗体的生成以及属性的设置
/// </summary>
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
	//生成的窗体句柄
	HWND WWhWnd;
	//指向鼠标文件的路径，如果值为NULL就使用IDC_ARROW鼠标资源
	WWCH WWcursorPath[100];
	//窗体的标题
	WWCH WWtitle[100];
	//窗体的风格
	LONG WWwindowStyle;
	//窗体的宽度
	WWINT WWwindowSizeX;
	//窗体的高度
	WWINT WWwindowSizeY;
	//窗体左上角的位置横坐标
	WWINT WWwindowPosX;
	//窗体左上角的位置纵坐标
	WWINT WWwindowPosY;
	//屏幕的宽度
	WWINT WWscreenSizeX;
	//屏幕的高度
	WWINT WWscreenSizeY;
	/// <summary>
	/// 通过成员变量WWwindowSize和WWwindowPos对窗口进行移动，以修改其大小和位置
	/// </summary>
	void WWMoveWindow();
public:
	/// <summary>
	/// 构造函数
	/// </summary>
	WWwindow();
	/// <summary>
	/// 初始化窗口
	/// </summary>
	/// <param name="hInstance">进程的句柄</param>
	void WWinitWnd(HINSTANCE hInstance);
	/// <summary>
	/// 显示窗口，可以重复调用，但是无意义
	/// </summary>
	void WWshowWnd();
	/// <summary>
	/// 隐藏窗口，可以重复调用，但是无意义
	/// </summary>
	void WWhideWnd();
	/// <summary>
	/// 全屏窗口，可以重复调用，但是无意义
	/// </summary>
	void WWfullScreen();
	/// <summary>
	/// 使窗体窗口化显示，可以重复调用，但是无意义
	/// </summary>
	void WWwindowScreen();
	/// <summary>
	/// 设置窗口具有最大化按钮
	/// </summary>
	void WWsetMaxButton();
	/// <summary>
	/// 获取窗口是否具有最大化按钮
	/// </summary>
	/// <returns>返回ture代表有最大化按钮，false代表没有</returns>
	WWBOOL WWgetMaxButton();
	/// <summary>
	/// 设置窗口不具有最大化按钮
	/// </summary>
	void WWremMaxButton();
	/// <summary>
	/// 设置窗口具有最小化按钮
	/// </summary>
	void WWsetMinButton();
	/// <summary>
	/// 获取窗口是否具有最小化按钮
	/// </summary>
	/// <returns>返回ture代表有最小化按钮，false代表没有</returns>
	WWBOOL WWgetMinButton();
	/// <summary>
	/// 设置窗口没有最小化按钮
	/// </summary>
	void WWremMinButton();
	/// <summary>
	/// 获取窗口句柄
	/// </summary>
	/// <returns>窗口句柄</returns>
	HWND WWgetHWnd();
	/// <summary>
	/// 设置窗口大小
	/// </summary>
	/// <param name="WWsizeX">窗口的宽度大小</param>
	/// <param name="WWsizeY">窗口的高度大小</param>
	void WWsetSize(WWINT WWsizeX,WWINT WWsizeY);
	/// <summary>
	/// 获取窗口大小
	/// </summary>
	/// <param name="WWselect">可选择WW_SEL_W获取窗口宽度，WW_SEL_H获取窗口高度</param>
	/// <returns>根据选择参数返回对应的值</returns>
	WWINT WWgetSize(WWSEL WWselect);
	/// <summary>
	/// 设置窗口左上角的位置
	/// </summary>
	/// <param name="WWposX">窗口左上角的横坐标</param>
	/// <param name="WWposY">窗口左上角的纵坐标</param>
	void WWsetPos(WWINT WWposX, WWINT WWposY);
	/// <summary>
	/// 获取窗口左上角的位置
	/// </summary>
	/// <param name="WWselect">可选择WW_SEL_X获取窗口左上角的横坐标，WW_SEL_Y获取窗口左上角的纵坐标</param>
	/// <returns>根据选择参数返回对应的值</returns>
	WWINT WWgetPos(WWSEL WWselect);
	/// <summary>
	/// 设置鼠标指针图标
	/// </summary>
	/// <param name="WWcursorPath">鼠标文件的路径（*.cur|*.ani）,如果传入NULL则使用IDC_ARROW资源对应的光标</param>
	void WWsetCursor(WWCH* WWcursorPath);
	/// <summary>
	/// 将窗体保存在文件中
	/// </summary>
	/// <param name="fp">文件的指针</param>
	void save(FILE* fp);
	/// <summary>
	/// 将窗体保存在文件中
	/// </summary>
	/// <param name="fp">文件的指针</param>
	void load(FILE* fp);

};