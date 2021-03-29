/// <summary>
/// 文件名称: WWwindow.cpp
/// 创建时间：2021/3/27
/// 创建人：	赵霄
/// 最后更新时间：2021/3/30
/// 文档描述：主窗体模块的源文件
/// </summary>
#include "WWwindow.h"
void WWwindow::WWMoveWindow()
{
	MoveWindow(WWhWnd, WWwindowPosX, WWwindowPosY, WWwindowSizeX, WWwindowSizeY, TRUE);
}

WWwindow::WWwindow()
{
	WWwnd = WNDCLASSEXW();
	//对窗口风格变量进行初始化
	WWwindowStyle = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	WWhWnd = NULL;
	//初始化窗口大小为900,600，位置位于显示器中央
	WWwindowSizeX = 900, WWwindowSizeY = 600;
	WWscreenSizeX = GetSystemMetrics(SM_CXSCREEN), WWscreenSizeY = GetSystemMetrics(SM_CYSCREEN);
	WWwindowPosX = (WWscreenSizeX - WWwindowSizeX) / 2, WWwindowPosY = (WWscreenSizeY - WWwindowSizeY) / 2;
	//默认鼠标为IDC_ARROW
	strcpy(WWcursorPath, "NULL");
	//默认标题为WWEngine
	strcpy(WWtitle, "WWEngine");
}

void WWwindow::WWinitWnd(HINSTANCE hInstance)
{
	WWwnd.cbSize = sizeof(WNDCLASSEXW);
	WWwnd.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	WWwnd.lpfnWndProc = WWframe::WindowProc;
	WWwnd.cbClsExtra = 0;
	WWwnd.cbWndExtra = 0;
	WWwnd.hInstance = hInstance;
	WWwnd.hIcon = NULL;
	WWwnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	WWwnd.hbrBackground = (HBRUSH)(BLACK_BRUSH);
	WWwnd.lpszMenuName = NULL;
	WWwnd.lpszClassName = L"WWEngine";
	WWwnd.hIconSm = NULL;
	//注册窗口类
	RegisterClassExW(&WWwnd);
	//创建窗口，其参数为类的成员变量
	WWhWnd = CreateWindowExW(
		NULL,
		L"WWEngine",
		L"WWEngine",
		WWwindowStyle,
		WWwindowPosX,
		WWwindowPosY,
		WWwindowSizeX,
		WWwindowSizeY,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (WWhWnd == NULL)
	{
		exit(-1);
	}
	//更新窗口
	UpdateWindow(WWhWnd);
}

void WWwindow::WWshowWnd()
{
	ShowWindow(WWhWnd, SW_SHOW);
}

void WWwindow::WWhideWnd()
{
	ShowWindow(WWhWnd, SW_HIDE);
}

void WWwindow::WWfullScreen()
{
	//设置窗口具有WS_POPUP风格，取消WS_OVERLAPPEDWINDOW风格
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW | WS_POPUP);
	//将窗口放在显示器左上角，设置大小为显示器像素值
	MoveWindow(WWhWnd, 0, 0, WWscreenSizeX, WWscreenSizeY, TRUE);
}

void WWwindow::WWwindowScreen()
{
	//设置窗口具有WS_OVERLAPPEDWINDOW风格，取消WS_POPUP风格
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) | WS_OVERLAPPEDWINDOW & ~WS_POPUP);
	//设置窗口为类的成员变量所存储的大小和位置
	MoveWindow(WWhWnd, WWwindowPosX, WWwindowPosY, WWwindowSizeX, WWwindowSizeY, TRUE);
}

void WWwindow::WWsetMaxButton()
{
	//同时在WWwindowStyle和窗口的style中加上最大化窗口风格
	WWwindowStyle |= WS_MAXIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) | WS_MAXIMIZEBOX);
}

WWBOOL WWwindow::WWgetMaxButton()
{
	return GetWindowLong(WWhWnd, GWL_STYLE) & WS_MAXIMIZEBOX;
}

void WWwindow::WWremMaxButton()
{
	//同时在WWwindowStyle和窗口的style中删除最大化窗口风格
	WWwindowStyle &= ~WS_MAXIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
}

HWND WWwindow::WWgetHWnd()
{
	return WWhWnd;
}

void WWwindow::WWsetSize(WWINT WWsizeX, WWINT WWsizeY)
{
	WWwindowSizeX = WWsizeX;
	WWwindowSizeY = WWsizeY;
	WWMoveWindow();
}

WWINT WWwindow::WWgetSize(WWSEL WWselect)
{
	if (WWselect == WW_SEL_W)return WWwindowSizeX;
	if (WWselect == WW_SEL_H)return WWwindowSizeY;
	else return -1;
}

void WWwindow::WWsetPos(WWINT WWposX, WWINT WWposY)
{
	WWwindowPosX = WWposX;
	WWwindowPosY = WWposY;
	WWMoveWindow();
}

WWINT WWwindow::WWgetPos(WWSEL WWselect)
{
	if (WWselect == WW_SEL_X)return WWwindowPosX;
	if (WWselect == WW_SEL_Y)return WWwindowPosY;
	else return -1;
}

void WWwindow::WWsetCursor(WWCH* WWcurPath)
{
	strcpy(WWcursorPath, WWcurPath);
	if (strcmp(WWcursorPath, "NULL") != 0)
	{
		WWwnd.hCursor = LoadCursorFromFile(T2W((LPTSTR)WWcursorPath));
		if (WWwnd.hCursor == NULL)
		{
#ifdef _DEBUG
			WWDEBUG("找不到鼠标文件");
#endif
			//如果读取文件失败则会使用IDC_ARROW资源的默认鼠标
			WWwnd.hCursor = LoadCursor(NULL, IDC_ARROW);
		}
	}
	else
	{
		WWwnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	}
}

void WWwindow::save(FILE* fp)
{
	//保存类的成员变量中需要持久化存储的内容
	fprintf(fp, "%u %s %s %d %d %d %d %d\n", WWwnd.style, WWcursorPath, WWtitle, WWwindowStyle, WWwindowSizeX, WWwindowSizeY, WWwindowPosX, WWwindowPosY);
}

void WWwindow::load(FILE* fp)
{
	//从文件中读取持久化存储的内容
	fscanf(fp, "%u %s %s %d %d %d %d %d\n", &WWwnd.style, WWcursorPath, WWtitle, &WWwindowStyle, &WWwindowSizeX, &WWwindowSizeY, &WWwindowPosX, &WWwindowPosY);
	if (strcmp(WWcursorPath, "NULL") != 0)
	{
		WWwnd.hCursor = LoadCursorFromFile(T2W((LPTSTR)WWcursorPath));
		if (WWwnd.hCursor == NULL)
		{
#ifdef _DEBUG
			WWDEBUG("找不到鼠标文件");
#endif
			//如果读取文件失败则会使用IDC_ARROW资源的默认鼠标
			WWwnd.hCursor = LoadCursor(NULL, IDC_ARROW);
		}
	}
	else
	{
		WWwnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	}
	SetWindowText(WWhWnd, T2W((LPTSTR)WWtitle));
	SetWindowLong(WWhWnd, GWL_STYLE, WWwindowStyle);
	//对窗口位置和大小进行设置
	if (WWwindowSizeX <= 0 || WWwindowSizeX > WWscreenSizeX)
	{
#ifdef _DEBUG
		WWDEBUG("WWwindowSizeX值超限");
#endif
		WWwindowSizeX = WWscreenSizeX / 2;
	}
	if (WWwindowSizeY <= 0 || WWwindowSizeY > WWscreenSizeY)
	{
#ifdef _DEBUG
		WWDEBUG("WWwindowSizeY值超限");
#endif
		WWwindowSizeY = WWscreenSizeY / 2;
	}
	if (WWwindowPosX <= 0 || WWwindowPosX > WWscreenSizeX)
	{
#ifdef _DEBUG
		WWDEBUG("WWwindowPosX值超限");
#endif
		WWwindowPosX = (WWscreenSizeX - WWwindowSizeX) / 2;
	}
	if (WWwindowPosY <= 0 || WWwindowPosX > WWscreenSizeY)
	{
#ifdef _DEBUG
		WWDEBUG("WWwindowPosY值超限");
#endif
		WWwindowPosY = (WWscreenSizeY - WWwindowSizeY) / 2;
	}
	WWMoveWindow();

}

void WWwindow::WWsetMinButton()
{
	//在WWwindowStyle和窗口style中同时加上最小化窗口的风格
	WWwindowStyle |= WS_MINIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) | WS_MINIMIZEBOX);
}

WWBOOL WWwindow::WWgetMinButton()
{
	return GetWindowLong(WWhWnd, GWL_STYLE) & WS_MINIMIZEBOX;
}

void WWwindow::WWremMinButton()
{
	//在WWwindowStyle和窗口style中同时删除最小化窗口的风格
	WWwindowStyle &= ~WS_MINIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
}

LRESULT WWframe::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// 消息分发
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
		throw std::string("click");
	case WM_SIZE:
		break;
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void WWframe::WWmsgCycle()
{
	MSG msg = { 0 };
	while (true)
	{
		if (msg.message == WM_DESTROY || msg.message == WM_CLOSE || msg.message == WM_QUIT)
		{
			break;
		}
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

#ifdef _DEBUG

void WWframe::WWlog(const WWCH* file, WWINT line, const WWCH* loginfo)
{
	fprintf(WWframe::WWlogPtr, "File: %s Line: %d Time: %s Info: %s\n", file, line, WWtime, loginfo);
}

void WWframe::WWlogNewLine()
{
	fprintf(WWframe::WWlogPtr, "\n");
}

void WWframe::createconsole()
{
	//创建控制台，设置窗口标题
	AllocConsole();
	SetConsoleCtrlHandler(NULL, true);
	SetConsoleTitle(L"WWEngine Console");
	//重新定义stdout到控制台，使程序支持printf进行格式化输出
	freopen("CONOUT$", "w+t", stdout);
}


void WWframe::debug(const WWCH* file, WWINT line,const WWCH* debuginfo)
{
	//格式化输出调试信息，包括文件，代码行数，时间以及调用函数时传递的调试信息
	printf("File: %s Line: %d Time: %s Info: %s\n", file, line, WWtime, debuginfo);
}

void WWframe::error(const WWCH* file, WWINT line, const WWCH* errorinfo)
{
	//格式化输出错误信息，首先将窗口文本颜色设置为红色，输出错误信息。
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("error: File: %s Line: %d Time: %s Info: %s\n", file, line, WWtime, errorinfo);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}



#endif// _DEBUG