#pragma once
#include"WWtype.h"
class WWkeyIO
{
private:
    static WWPT P1;
    //������
    static WWBOOL Mutex[260];
    //����̧��״̬����
    static WWBOOL WWarrUp[260];
    //��������״̬����
    static WWBOOL WWarrDown[260];
    //˫������
    static WWBOOL WWDCarr[260];
    //��������
    static WWBOOL WWSCarr[260];
    //��¼����ʱ��
    static WWTIME WWTimeDown[260];
    //��¼̧��ʱ��
    static WWTIME WWTimeUp[260];
public:
    //����ÿ����������
    static void WWkeyset(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lPrarm, WWTIME time);
    //�õ��������
    static WWPT WWGetPoint();
    //�������ǰ���
    static WWBOOL WWgetDown(WPARAM wParam);
    //�������Ƿ�̧��
    static WWBOOL WWgetUP(WPARAM wParam);
    //�������Ƿ񱻵���
    static WWBOOL WWgetSclick(WPARAM wParam);
    //�������Ƿ�˫�� ����Ϊ�������
    static WWBOOL WWgetDclick(WPARAM wParam);
    //����������Ƿ񱻰���
    static WWBOOL WWgetLdown();
    //����������Ƿ�̧��
    static WWBOOL WWgetLup();
    static WWBOOL WWgetRdown();
    static WWBOOL WWgetRup();
    static void WWonTimer(WWINT keyID, WWINT clickTime);
};


