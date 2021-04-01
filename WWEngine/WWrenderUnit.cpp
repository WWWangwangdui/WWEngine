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
        WWERROR("��ͼԪ�ı任��������ڣ��޷����л���");
        return WWPT();
    }
    return WWPT{};//������
}

WWINT WWrenderUnit::WWgetGlobleRotate()
{
    return WWINT();//������
}

WWINT WWrenderUnit::WWgetGlobleScale()
{
    return WWINT();//������
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
