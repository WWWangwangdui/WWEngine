#pragma once
#include<afx.h>
#include<d2d1.h>
#include<dwrite.h>
#include "WWmoduleBase.h"
#include"WWwindow.h"
#include"WWtype.h"
#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")
class transform;
class WWrenderUnit :
    private WWmoduleBase
{
private:
    transform* WWobjtrans;
public:
    WWINT WWlayer;
    WWINT WWposX;
    WWINT WWposY;
    WWINT WWrotate;
    WWFLOAT WWscaleX;
    WWFLOAT WWscaleY;
    ID2D1SolidColorBrush* WWbrush;
    IDWriteTextFormat* WWformat;
    WWSTR WWstr;
    WWBitmap* WWbit;
    WWAnimation* WWani;
    WWSEL WWunitType;
    WWrenderUnit();
    ~WWrenderUnit();
    WWPT WWgetGloblePt();
    WWINT WWgetGlobleRotate();
    WWINT WWgetGlobleScale();
    WWBOOL WWsetUnitStr(WWSTR WWs,WWSTR WWfont,WWFLOAT WWsize);
    WWBOOL WWsetUnitBit(WWBitmap* WWsrc);
    WWBOOL WWsetUnitGraph(WWSEL wssel, WWINT R, WWINT G, WWINT B, WWINT Wide);
    WWBOOL WWsetUnitAnimat(WWAnimation* WWsrc);
    void WWflushAnimat();
    void WWstopAnimat();
    void WWbeginAnimat();
    void init();
    void save(FILE* p);
    void update();
    void load(FILE* p);
};

