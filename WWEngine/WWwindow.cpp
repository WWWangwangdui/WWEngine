/// <summary>
/// 文件名称: WWwindow.cpp
/// 创建时间：2021/3/27
/// 创建人：	赵霄
/// 最后更新时间：2021/3/28
/// 文档描述：主窗体模块的源文件
/// </summary>
#include "WWwindow.h"
void WWwindow::WWMoveWindow()
{
	MoveWindow(WWhWnd, WWwindowPosX, WWwindowPosY, WWwindowSizeX, WWwindowSizeY, TRUE);
}
/// <summary>
/// 类的无参构造函数
/// </summary>
WWwindow::WWwindow()
{
	WWwnd = WNDCLASSEXW();
	WWwindowStyle = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	WWhWnd = NULL;
	WWwindowSizeX = 900, WWwindowSizeY = 600;
	WWscreenSizeX = GetSystemMetrics(SM_CXSCREEN), WWscreenSizeY = GetSystemMetrics(SM_CYSCREEN);
	WWwindowPosX = (WWscreenSizeX - WWwindowSizeX) / 2, WWwindowPosY = (WWscreenSizeY - WWwindowSizeY) / 2;
	strcpy(WWcursorPath, "NULL");
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
	//WWwnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	WWwnd.hCursor = LoadCursorFromFile(L"C:\\Users\\50431\\Downloads\\JadeDreams\\JadeDreams\\Arrow.ani");
	WWwnd.hbrBackground = (HBRUSH)(BLACK_BRUSH);
	WWwnd.lpszMenuName = NULL;
	WWwnd.lpszClassName = L"WWEngine";
	WWwnd.hIconSm = NULL;
	RegisterClassExW(&WWwnd);
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
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW | WS_POPUP);
	MoveWindow(WWhWnd, 0, 0, WWscreenSizeX, WWscreenSizeY, TRUE);
}

void WWwindow::WWwindowScreen()
{
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) | WS_OVERLAPPEDWINDOW & ~WS_POPUP);
	MoveWindow(WWhWnd, WWwindowPosX, WWwindowPosY, WWwindowSizeX, WWwindowSizeY, TRUE);
}

void WWwindow::WWsetMaxButton()
{
	WWwindowStyle |= WS_MAXIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) | WS_MAXIMIZEBOX);
}

bool WWwindow::WWgetMaxButton()
{
	return GetWindowLong(WWhWnd, GWL_STYLE) & WS_MAXIMIZEBOX;
}

void WWwindow::WWremMaxButton()
{
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

void WWwindow::save(FILE* fp)
{
	fprintf(fp, "%u %s %s %d %d %d %d %d\n", WWwnd.style, WWcursorPath, WWtitle, WWwindowStyle, WWwindowSizeX, WWwindowSizeY, WWwindowPosX, WWwindowPosY);
}

void WWwindow::load(FILE* fp)
{

}

void WWwindow::WWsetMinButton()
{
	WWwindowStyle |= WS_MINIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) | WS_MINIMIZEBOX);
}

bool WWwindow::WWgetMinButton()
{
	return GetWindowLong(WWhWnd, GWL_STYLE) & WS_MINIMIZEBOX;
}

void WWwindow::WWremMinButton()
{
	WWwindowStyle &= ~WS_MINIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
}

LRESULT WWframe::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
		WWDEBUG("click");
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
void WWframe::createconsole()
{
	AllocConsole();
	SetConsoleCtrlHandler(NULL, true);
	SetConsoleTitle(L"WWEngine Console");
	freopen("CONOUT$", "w+t", stdout);
}

void WWframe::debug(const WWCH* file, WWINT line,const WWCH* debuginfo)
{
	printf("File: %s Line: %d Time: %s Info: %s\n", file, line, WWtime, debuginfo);
}

#endif// _DEBUG