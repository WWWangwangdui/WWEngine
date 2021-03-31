#pragma once
#include "WWmoduleBase.h"
class transform;
class WWrenderUnit :
    private WWmoduleBase
{
private:
    transform* WWobjtrans;
public:
    WWINT WWposX;
    WWINT WWposY;
    WWINT WWrotate;
    WWINT WWscaleX;
    WWINT WWscaleY;
    WWINT WWaniTime;
    WWINT WWaniFrameCnt;
    ID2D1SolidColorBrush* WWbrush;
    IDWriteTextFormat* WWformat;
    ID2D1Bitmap* WWbitmap;
    WWSTR WWstr;
    WWPT WWbitoff;
    WWPT WWbitSize;
    WWSEL WWunitType;
    WWrenderUnit();
    ~WWrenderUnit();
    WWPT WWgetGloblePt();
    WWBOOL WWsetUnitStr(WWSTR WWs,WWSTR WWfont,WWFLOAT WWsize);
    WWBOOL WWsetUnitBit(WWBIT* src);
    WWBOOL WWsetUnitGraph(WWSEL wssel,)
};

