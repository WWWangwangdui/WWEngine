/// <summary>
/// �ļ�����: WWwindow.cpp
/// ����ʱ�䣺2021/3/27
/// �����ˣ�	����
/// ������ʱ�䣺2021/3/30
/// �ĵ�������������ģ���Դ�ļ�
/// </summary>
#include "WWwindow.h"
void WWwindow::WWMoveWindow()
{
	MoveWindow(WWhWnd, WWwindowPosX, WWwindowPosY, WWwindowSizeX, WWwindowSizeY, TRUE);
}

WWwindow::WWwindow()
{
	WWwnd = WNDCLASSEXW();
	//�Դ��ڷ��������г�ʼ��
	WWwindowStyle = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	WWhWnd = NULL;
	//��ʼ�����ڴ�СΪ900,600��λ��λ����ʾ������
	WWwindowSizeX = 900, WWwindowSizeY = 600;
	WWscreenSizeX = GetSystemMetrics(SM_CXSCREEN), WWscreenSizeY = GetSystemMetrics(SM_CYSCREEN);
	WWwindowPosX = (WWscreenSizeX - WWwindowSizeX) / 2, WWwindowPosY = (WWscreenSizeY - WWwindowSizeY) / 2;
	//Ĭ�����ΪIDC_ARROW
	strcpy(WWcursorPath, "NULL");
	//Ĭ�ϱ���ΪWWEngine
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
	//ע�ᴰ����
	RegisterClassExW(&WWwnd);
	//�������ڣ������Ϊ��ĳ�Ա����
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
	//���´���
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
	//���ô��ھ���WS_POPUP���ȡ��WS_OVERLAPPEDWINDOW���
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) & ~WS_OVERLAPPEDWINDOW | WS_POPUP);
	//�����ڷ�����ʾ�����Ͻǣ����ô�СΪ��ʾ������ֵ
	MoveWindow(WWhWnd, 0, 0, WWscreenSizeX, WWscreenSizeY, TRUE);
}

void WWwindow::WWwindowScreen()
{
	//���ô��ھ���WS_OVERLAPPEDWINDOW���ȡ��WS_POPUP���
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) | WS_OVERLAPPEDWINDOW & ~WS_POPUP);
	//���ô���Ϊ��ĳ�Ա�������洢�Ĵ�С��λ��
	MoveWindow(WWhWnd, WWwindowPosX, WWwindowPosY, WWwindowSizeX, WWwindowSizeY, TRUE);
}

void WWwindow::WWsetMaxButton()
{
	//ͬʱ��WWwindowStyle�ʹ��ڵ�style�м�����󻯴��ڷ��
	WWwindowStyle |= WS_MAXIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) | WS_MAXIMIZEBOX);
}

WWBOOL WWwindow::WWgetMaxButton()
{
	return GetWindowLong(WWhWnd, GWL_STYLE) & WS_MAXIMIZEBOX;
}

void WWwindow::WWremMaxButton()
{
	//ͬʱ��WWwindowStyle�ʹ��ڵ�style��ɾ����󻯴��ڷ��
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
			WWDEBUG("�Ҳ�������ļ�");
#endif
			//�����ȡ�ļ�ʧ�����ʹ��IDC_ARROW��Դ��Ĭ�����
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
	//������ĳ�Ա��������Ҫ�־û��洢������
	fprintf(fp, "%u %s %s %d %d %d %d %d\n", WWwnd.style, WWcursorPath, WWtitle, WWwindowStyle, WWwindowSizeX, WWwindowSizeY, WWwindowPosX, WWwindowPosY);
}

void WWwindow::load(FILE* fp)
{
	//���ļ��ж�ȡ�־û��洢������
	fscanf(fp, "%u %s %s %d %d %d %d %d\n", &WWwnd.style, WWcursorPath, WWtitle, &WWwindowStyle, &WWwindowSizeX, &WWwindowSizeY, &WWwindowPosX, &WWwindowPosY);
	if (strcmp(WWcursorPath, "NULL") != 0)
	{
		WWwnd.hCursor = LoadCursorFromFile(T2W((LPTSTR)WWcursorPath));
		if (WWwnd.hCursor == NULL)
		{
#ifdef _DEBUG
			WWDEBUG("�Ҳ�������ļ�");
#endif
			//�����ȡ�ļ�ʧ�����ʹ��IDC_ARROW��Դ��Ĭ�����
			WWwnd.hCursor = LoadCursor(NULL, IDC_ARROW);
		}
	}
	else
	{
		WWwnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	}
	SetWindowText(WWhWnd, T2W((LPTSTR)WWtitle));
	SetWindowLong(WWhWnd, GWL_STYLE, WWwindowStyle);
	//�Դ���λ�úʹ�С��������
	if (WWwindowSizeX <= 0 || WWwindowSizeX > WWscreenSizeX)
	{
#ifdef _DEBUG
		WWDEBUG("WWwindowSizeXֵ����");
#endif
		WWwindowSizeX = WWscreenSizeX / 2;
	}
	if (WWwindowSizeY <= 0 || WWwindowSizeY > WWscreenSizeY)
	{
#ifdef _DEBUG
		WWDEBUG("WWwindowSizeYֵ����");
#endif
		WWwindowSizeY = WWscreenSizeY / 2;
	}
	if (WWwindowPosX <= 0 || WWwindowPosX > WWscreenSizeX)
	{
#ifdef _DEBUG
		WWDEBUG("WWwindowPosXֵ����");
#endif
		WWwindowPosX = (WWscreenSizeX - WWwindowSizeX) / 2;
	}
	if (WWwindowPosY <= 0 || WWwindowPosX > WWscreenSizeY)
	{
#ifdef _DEBUG
		WWDEBUG("WWwindowPosYֵ����");
#endif
		WWwindowPosY = (WWscreenSizeY - WWwindowSizeY) / 2;
	}
	WWMoveWindow();

}

void WWwindow::WWsetMinButton()
{
	//��WWwindowStyle�ʹ���style��ͬʱ������С�����ڵķ��
	WWwindowStyle |= WS_MINIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) | WS_MINIMIZEBOX);
}

WWBOOL WWwindow::WWgetMinButton()
{
	return GetWindowLong(WWhWnd, GWL_STYLE) & WS_MINIMIZEBOX;
}

void WWwindow::WWremMinButton()
{
	//��WWwindowStyle�ʹ���style��ͬʱɾ����С�����ڵķ��
	WWwindowStyle &= ~WS_MINIMIZEBOX;
	SetWindowLong(WWhWnd, GWL_STYLE, GetWindowLong(WWhWnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
}

LRESULT WWframe::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// ��Ϣ�ַ�
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
	//��������̨�����ô��ڱ���
	AllocConsole();
	SetConsoleCtrlHandler(NULL, true);
	SetConsoleTitle(L"WWEngine Console");
	//���¶���stdout������̨��ʹ����֧��printf���и�ʽ�����
	freopen("CONOUT$", "w+t", stdout);
}


void WWframe::debug(const WWCH* file, WWINT line,const WWCH* debuginfo)
{
	//��ʽ�����������Ϣ�������ļ�������������ʱ���Լ����ú���ʱ���ݵĵ�����Ϣ
	printf("File: %s Line: %d Time: %s Info: %s\n", file, line, WWtime, debuginfo);
}

void WWframe::error(const WWCH* file, WWINT line, const WWCH* errorinfo)
{
	//��ʽ�����������Ϣ�����Ƚ������ı���ɫ����Ϊ��ɫ�����������Ϣ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("error: File: %s Line: %d Time: %s Info: %s\n", file, line, WWtime, errorinfo);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}



#endif// _DEBUG