#pragma once
#include"WWtype.h"
class WWkeyIO
{
private:
    static WWPT P1;
    //互斥锁
    static WWBOOL Mutex[260];
    //按键抬起状态数组
    static WWBOOL WWarrUp[260];
    //按键按下状态数组
    static WWBOOL WWarrDown[260];
    //双击数组
    static WWBOOL WWDCarr[260];
    //单击数组
    static WWBOOL WWSCarr[260];
    //记录按下时间
    static WWTIME WWTimeDown[260];
    //记录抬起时间
    static WWTIME WWTimeUp[260];
public:
    //设置每个按键数组
    static void WWkeyset(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lPrarm, WWTIME time);
    //得到鼠标坐标
    static WWPT WWGetPoint();
    //检测键盘是按下
    static WWBOOL WWgetDown(WPARAM wParam);
    //检测键盘是否抬起
    static WWBOOL WWgetUP(WPARAM wParam);
    //检测键盘是否被单击
    static WWBOOL WWgetSclick(WPARAM wParam);
    //检测键盘是否双击 参数为虚拟键码
    static WWBOOL WWgetDclick(WPARAM wParam);
    //检测鼠标左键是否被按下
    static WWBOOL WWgetLdown();
    //检测鼠标左键是否抬起
    static WWBOOL WWgetLup();
    static WWBOOL WWgetRdown();
    static WWBOOL WWgetRup();
    static void WWonTimer(WWINT keyID, WWINT clickTime);
};


