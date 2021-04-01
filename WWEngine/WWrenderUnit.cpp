#include "WWrenderUnit.h"

WWrenderUnit::WWrenderUnit()
{
    WWlayer = 0;
    WWposX = 0;
    WWposY = 0;
    WWrotate = 0;
    WWscaleX = WWscaleY = 1.0;
    WWbrush = nullptr;
    WWformat = nullptr;
    WWstr = nullptr;
    WWbit = nullptr;
    WWani = nullptr;
    WWunitType = WW_SEL_EMPTY;
    WWactivity = true;
    WWobjtrans = nullptr;
}

WWrenderUnit::~WWrenderUnit()
{
    WWDELETE(WWbrush);
    WWDELETE(WWformat);
    WWDELETE(WWbit);
    WWDELETE(WWani);
}

WWPT WWrenderUnit::WWgetGloblePt()
{
    if (WWobjtrans == nullptr)
    {
        WWERROR("该图元的变换组件不存在，无法进行绘制");
        return WWPT();
    }
    return WWPT{};//待补充
}

WWINT WWrenderUnit::WWgetGlobleRotate()
{
    return WWINT();//待补充
}

WWINT WWrenderUnit::WWgetGlobleScale()
{
    return WWINT();//待补充
}

WWBOOL WWrenderUnit::WWsetUnitStr(WWSTR WWs, WWSTR WWfont, WWFLOAT WWsize)
{
    return WWBOOL();
}

WWBOOL WWrenderUnit::WWsetUnitBit(WWBitmap* WWsrc)
{
    return WWBOOL();
}

WWBOOL WWrenderUnit::WWsetUnitGraph(WWSEL wssel, WWINT R, WWINT G, WWINT B, WWINT Wide)
{
    return WWBOOL();
}

WWBOOL WWrenderUnit::WWsetUnitAnimat(WWAnimation* WWsrc)
{
    return WWBOOL();
}

void WWrenderUnit::WWflushAnimat()
{
}

void WWrenderUnit::WWstopAnimat()
{
}

void WWrenderUnit::WWbeginAnimat()
{
}

void WWrenderUnit::init()
{
}


void WWrenderUnit::save(FILE* p)
{
}

void WWrenderUnit::update()
{
}

void WWrenderUnit::load(FILE* p)
{
}
