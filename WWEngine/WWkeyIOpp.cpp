#include"WWkeyIO.h"
#include"WWwindow.h"
WWPT WWkeyIO::P1;
WWBOOL WWkeyIO::Mutex[260] = { 0 };                 //������
WWBOOL WWkeyIO::WWarrUp[260] = { 0 };               //��������/̧��״̬����
WWBOOL WWkeyIO::WWarrDown[260] = { 0 };             //��������/̧��״̬����
WWBOOL WWkeyIO::WWDCarr[260] = { 0 };                //˫��״̬����
WWBOOL WWkeyIO::WWSCarr[260] = { 0 };                 //����״̬����
WWTIME WWkeyIO::WWTimeDown[260] = { 0 };          //��¼���µ�ʱ��
WWTIME WWkeyIO::WWTimeUp[260] = { 0 };            //��¼̧���ʱ��
void WWkeyIO::WWkeyset(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lPrarm, WWTIME time)
{
    if (uMsg == WM_KEYUP) { Mutex[wParam] = 0; }
    if (Mutex[wParam] == 1)return;

    //���°���
    if (uMsg == WM_KEYDOWN || uMsg == WM_SYSKEYDOWN)
    {
        WWarrDown[wParam] = 1;
        WWTimeDown[wParam] = time;
        Mutex[wParam] = 1;
    }
    //̧�𰴼�
    if (uMsg == WM_KEYUP || uMsg == WM_SYSKEYUP)
    {
        WWarrUp[wParam] = 1;
        WWTimeUp[wParam] = time;
    }
    //��������

    if (uMsg == WM_KEYUP)
    {
        if (time - WWTimeDown[wParam] < 200)
        {
            WWSCarr[wParam] = 1;
            WWframe::WWaddKeyTimer(wParam, 1);
        }
    }
    //˫������
    if (uMsg == WM_KEYDOWN)
    {
        if (time - WWTimeUp[wParam] < 200)
        {
            WWDCarr[wParam] = 1;
            WWframe::WWaddKeyTimer(wParam, 2);
        }
    }
    //����������
    if (uMsg == WM_LBUTTONDOWN)
    {
        WWarrDown[1] = 1;
    }
    //������̧��
    if (uMsg == WM_LBUTTONUP)
    {
        WWarrUp[1] = 1;
    }
    //����Ҽ�����
    if (uMsg == WM_RBUTTONDOWN)
    {
        ;
        WWarrDown[2] = 1;
    }
    //����Ҽ�̧��
    if (uMsg == WM_RBUTTONDOWN)
    {
        WWarrUp[2] = 1;
    }
    //�õ�����
    if (uMsg == WM_LBUTTONDOWN || uMsg == WM_LBUTTONUP || uMsg == WM_RBUTTONDOWN || uMsg == WM_RBUTTONUP || uMsg == WM_MBUTTONDOWN || uMsg == WM_MBUTTONUP)
    {
        P1.x = lPrarm & 0xffff;
        P1.y = lPrarm >> 16;
    }
    if (uMsg == WM_KEYDOWN)
    {
        WWTimeDown[wParam] = time;
    }
    if (uMsg == WM_KEYUP)
    {
        WWTimeUp[wParam] = time;
    }
    return;
}

WWPT WWkeyIO::WWGetPoint() 
{
    return P1;
}

WWBOOL WWkeyIO::WWgetDown(WPARAM wParam) 
{
    if (WWarrDown[wParam] == 1 && wParam > 5)
    {
        return true;
    }
    else
        return false;
}

WWBOOL WWkeyIO::WWgetUP(WPARAM wParam)
{

    if (WWarrUp[wParam] == 1 && wParam > 5) 
    {
        return true;
    }
    else
        return false;

}

WWBOOL WWkeyIO::WWgetSclick(WPARAM wParam)
{
    if (WWSCarr[wParam] == 1 && wParam > 5) 
    {
        WWSCarr[wParam] = false;
        return true;
    }
    else
        return false;
}

WWBOOL WWkeyIO::WWgetDclick(WPARAM wParam)
{
    if (WWDCarr[wParam] == 1 && wParam > 5) 
    {
        WWDCarr[wParam] = false;
        return true;
    }
    else
        return false;
}
WWBOOL WWkeyIO::WWgetLdown()
{
    if (WWarrDown[1] == 1) 
    {
        return true;
    }
    else
        return false;
}

WWBOOL WWkeyIO::WWgetLup()
{
    if (WWarrUp[1] == 1)
    {
        return true;
    }
    else
        return false;
}

WWBOOL WWkeyIO::WWgetRdown()
{
    if (WWarrDown[2] == 1)
    {
        return true;
    }
    else
        return false;
}

WWBOOL WWkeyIO::WWgetRup()
{
    if (WWarrUp[2] == 1)
    {
        if (WWarrDown[2] == 1)
        {
            return true;
        }
        else
            return false;
    }
}
void WWkeyIO::WWonTimer(WWINT keyID, WWINT clickTime)
{
    if (clickTime == 1)
    {
        WWSCarr[keyID] = false;
    }
    else
    {
        WWDCarr[keyID] = false;
    }
}
