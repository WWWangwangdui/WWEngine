#pragma once
#include"WWtype.h"
#include"WWmoduleBase.h"
class WWrenderUnit :
    public WWmoduleBase
{
private:
    WWtransform* WWobjtrans;
    WWBOOL WWlockAtCamera;
    WWBOOL WWnewSrc;
public:
    RECT WWdrawRect;
    WWINT WWlayer;
    WWINT WWposX;
    WWINT WWposY;
    WWINT WWrotate;
    WWFLOAT WWscaleX;
    WWFLOAT WWscaleY;
    WWPT WWcenter;
    ID2D1SolidColorBrush* WWbrush;
    
    IDWriteTextFormat* WWformat;


    IDWriteTextLayout* WWtextLayout;
    WWText* WWtext;
    WWBitmap* WWbit;
    WWGraph* WWgra;
    WWAnimation* WWani;
    WWSEL WWunitType;
    WWTIME WWaniTime;
    WWBOOL WWaniAct;
    WWPT pt1;
    WWPT pt2;
    WWrenderUnit();
    ~WWrenderUnit();
    WWPT WWgetGloblePt();
    WWINT WWgetGlobleRotate();
    WWPTF WWgetGlobleScale();
    WWBOOL WWsetUnitStr(WWText* WWsrc);
    WWBOOL WWsetUnitBit(WWBitmap* WWsrc);
    WWBOOL WWsetUnitGraph(WWGraph* WWsrc);
    WWBOOL WWsetUnitAnimat(WWAnimation* WWsrc);
    void WWflushAnimat();
    void WWstopAnimat();
    void WWbeginAnimat();
    void WWclear();
    void WWinit();
    void WWinit(WWobject* father);
    void WWsave(FILE* p);
    void WWupdate();
    void WWload(FILE* p);
    WWBOOL WWcreateDevRes();
    void WWrender();
    WWPT WWgetCenter();
};

