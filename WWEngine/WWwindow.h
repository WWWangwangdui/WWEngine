/// <summary>
/// �ļ�����: WWwindow.h
/// ����ʱ�䣺2021/3/27
/// �����ˣ�	����
/// ������ʱ�䣺2021/3/29
/// �ĵ�������������ģ���ͷ�ļ�
/// </summary>
#pragma once
#include<Windows.h>
#include<iostream>
#include<atlbase.h>
#include<atlstr.h>
#include"WWdefine.h"
/// <summary>
/// WWframe��Ϊ�ṩ�������ܵľ�̬�࣬�书����Ҫ��������Ļص��������������Ϣѭ��
/// ��_DEBUGģʽ�£����໹���ṩ���ڵ��ԵĿ���̨�Լ�debug��Ϣ��error��Ϣ�Ĵ�ӡ
/// </summary>
static class WWframe
{
private:
public:
	// ��̬�ַ��������ʱ�䣬��ʱ�����debug��error����������Ϸ����ģ�����ά��
	static WWCH* WWtime;
	// ��̬�ַ�������ų�����־��·��
	static const WWCH* WWlogPath;
	// ��̬�ļ�ָ�룬ָ����־�ļ�
	static FILE* WWlogPtr;
	/// <summary>
	/// ����Ļص�����
	/// </summary>
	/// <param name="hWnd">�յ���Ϣ�Ĵ���ľ��</param>
	/// <param name="uMsg">��Ϣ�ı��</param>
	/// <param name="wParam">16λ����</param>
	/// <param name="lParam">32λ����</param>
	/// <returns></returns>
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	/// <summary>
	/// ��Ϣѭ��
	/// </summary>
	static void WWmsgCycle();
	/// <summary>
	/// ��д������־
	/// </summary>
	/// <param name="file">���������ļ���</param>
	/// <param name="line">������������</param>
	/// <param name="debuginfo">��־��Ϣ</param>
	static void WWlog(const WWCH* file, WWINT line, const WWCH* loginfo);
	/// <summary>
	/// ����־�ļ��л�һ������
	/// </summary>
	static void WWlogNewLine();
#ifdef _DEBUG
public:
	/// <summary>
	/// �������Կ���̨
	/// </summary>
	static void createconsole();
	/// <summary>
	/// ���������Ϣ
	/// </summary>
	/// <param name="file">�ļ�·��</param>
	/// <param name="line">��������</param>
	/// <param name="debuginfo">������Ϣ</param>
	static void debug(const WWCH* file, WWINT line,const WWCH* debuginfo);
	/// <summary>
	/// ���������Ϣ
	/// </summary>
	/// <param name="file">�ļ�·��</param>
	/// <param name="line">��������</param>
	/// <param name="errorinfo">������Ϣ</param>
	static void error(const WWCH* file, WWINT line, const WWCH* errorinfo);
#endif// DEBUG

};

/// <summary>
/// WWwindow���Ƕ���������е�һϵ�з�װ��ͨ�����ʵ������������ʵ�ִ���������Լ����Ե�����
/// </summary>
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
	//���ɵĴ�����
	HWND WWhWnd;
	//ָ������ļ���·�������ֵΪNULL��ʹ��IDC_ARROW�����Դ
	WWCH WWcursorPath[100];
	//����ı���
	WWCH WWtitle[100];
	//����ķ��
	LONG WWwindowStyle;
	//����Ŀ��
	WWINT WWwindowSizeX;
	//����ĸ߶�
	WWINT WWwindowSizeY;
	//�������Ͻǵ�λ�ú�����
	WWINT WWwindowPosX;
	//�������Ͻǵ�λ��������
	WWINT WWwindowPosY;
	//��Ļ�Ŀ��
	WWINT WWscreenSizeX;
	//��Ļ�ĸ߶�
	WWINT WWscreenSizeY;
	/// <summary>
	/// ͨ����Ա����WWwindowSize��WWwindowPos�Դ��ڽ����ƶ������޸����С��λ��
	/// </summary>
	void WWMoveWindow();
public:
	/// <summary>
	/// ���캯��
	/// </summary>
	WWwindow();
	/// <summary>
	/// ��ʼ������
	/// </summary>
	/// <param name="hInstance">���̵ľ��</param>
	void WWinitWnd(HINSTANCE hInstance);
	/// <summary>
	/// ��ʾ���ڣ������ظ����ã�����������
	/// </summary>
	void WWshowWnd();
	/// <summary>
	/// ���ش��ڣ������ظ����ã�����������
	/// </summary>
	void WWhideWnd();
	/// <summary>
	/// ȫ�����ڣ������ظ����ã�����������
	/// </summary>
	void WWfullScreen();
	/// <summary>
	/// ʹ���崰�ڻ���ʾ�������ظ����ã�����������
	/// </summary>
	void WWwindowScreen();
	/// <summary>
	/// ���ô��ھ�����󻯰�ť
	/// </summary>
	void WWsetMaxButton();
	/// <summary>
	/// ��ȡ�����Ƿ������󻯰�ť
	/// </summary>
	/// <returns>����ture��������󻯰�ť��false����û��</returns>
	WWBOOL WWgetMaxButton();
	/// <summary>
	/// ���ô��ڲ�������󻯰�ť
	/// </summary>
	void WWremMaxButton();
	/// <summary>
	/// ���ô��ھ�����С����ť
	/// </summary>
	void WWsetMinButton();
	/// <summary>
	/// ��ȡ�����Ƿ������С����ť
	/// </summary>
	/// <returns>����ture��������С����ť��false����û��</returns>
	WWBOOL WWgetMinButton();
	/// <summary>
	/// ���ô���û����С����ť
	/// </summary>
	void WWremMinButton();
	/// <summary>
	/// ��ȡ���ھ��
	/// </summary>
	/// <returns>���ھ��</returns>
	HWND WWgetHWnd();
	/// <summary>
	/// ���ô��ڴ�С
	/// </summary>
	/// <param name="WWsizeX">���ڵĿ�ȴ�С</param>
	/// <param name="WWsizeY">���ڵĸ߶ȴ�С</param>
	void WWsetSize(WWINT WWsizeX,WWINT WWsizeY);
	/// <summary>
	/// ��ȡ���ڴ�С
	/// </summary>
	/// <param name="WWselect">��ѡ��WW_SEL_W��ȡ���ڿ�ȣ�WW_SEL_H��ȡ���ڸ߶�</param>
	/// <returns>����ѡ��������ض�Ӧ��ֵ</returns>
	WWINT WWgetSize(WWSEL WWselect);
	/// <summary>
	/// ���ô������Ͻǵ�λ��
	/// </summary>
	/// <param name="WWposX">�������Ͻǵĺ�����</param>
	/// <param name="WWposY">�������Ͻǵ�������</param>
	void WWsetPos(WWINT WWposX, WWINT WWposY);
	/// <summary>
	/// ��ȡ�������Ͻǵ�λ��
	/// </summary>
	/// <param name="WWselect">��ѡ��WW_SEL_X��ȡ�������Ͻǵĺ����꣬WW_SEL_Y��ȡ�������Ͻǵ�������</param>
	/// <returns>����ѡ��������ض�Ӧ��ֵ</returns>
	WWINT WWgetPos(WWSEL WWselect);
	/// <summary>
	/// �������ָ��ͼ��
	/// </summary>
	/// <param name="WWcursorPath">����ļ���·����*.cur|*.ani��,�������NULL��ʹ��IDC_ARROW��Դ��Ӧ�Ĺ��</param>
	void WWsetCursor(WWCH* WWcursorPath);
	/// <summary>
	/// �����屣�����ļ���
	/// </summary>
	/// <param name="fp">�ļ���ָ��</param>
	void save(FILE* fp);
	/// <summary>
	/// �����屣�����ļ���
	/// </summary>
	/// <param name="fp">�ļ���ָ��</param>
	void load(FILE* fp);

};