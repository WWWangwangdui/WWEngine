#pragma once
#include "WWmoduleBase.h"
class transform;
class WWrenderUnit :
    private WWmoduleBase
{
private:
    transform* WWobjtrans;
    WWINT WWposX;
    WWINT WWposY;
    WWINT WWrotate;
    WWINT WWscaleX;
    WWINT WWscaleY;
    ID2D1SolidColorBrush* WWbrush;
    IDWriteTextFormat* WWformat;


};

