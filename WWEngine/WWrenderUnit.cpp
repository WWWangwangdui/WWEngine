#include "WWrenderUnit.h"
#include"WWrenderer.h"
#include"WWtransform.h"
#include"WWwindow.h"
#include"WWcamera.h"
#include"WWobject.h"

WWrenderUnit::WWrenderUnit()
{
    WWlayer = 0;
    WWposX = 0;
    WWposY = 0;
    WWrotate = 0;
    WWscaleX = WWscaleY = 1.0;
    WWbrush = nullptr;
    WWformat = nullptr;
    WWtext = nullptr;
    WWbit = nullptr;
    WWani = nullptr;
    WWgra = nullptr;
    WWunitType = WW_SEL_EMPTY;
    WWactivity = true;
    WWobjtrans = nullptr;
    WWmoduleName = "renderUnit";
}

WWrenderUnit::~WWrenderUnit()
{
    WWDELETE(WWbrush);
    WWDELETE(WWformat);
    WWDELETE(WWbit);
    WWDELETE(WWani);
    WWDELETE(WWgra);

}

WWPT WWrenderUnit::WWgetGloblePt()
{
    if (WWobjtrans == nullptr)
    {
        WWERROR("��ͼԪ�ı任��������ڣ��޷����л���");
        return WWPT();
    }
    WWPT pt = WWobjtrans->WWgetPos();
    pt.x += WWposX;
    pt.y += WWposY;
    return pt;
}

WWINT WWrenderUnit::WWgetGlobleRotate()
{
    if (WWobjtrans == nullptr)
    {
        WWERROR("��ͼԪ�ı任��������ڣ��޷����л���");
        return WWINT();
    }
    return (WWobjtrans->WWgetRotate() + WWrotate) % 360;//������
}

WWPTF WWrenderUnit::WWgetGlobleScale()
{
    if (WWobjtrans == nullptr)
    {
        WWERROR("��ͼԪ�ı任��������ڣ��޷����л���");
        return WWPTF();
    }
    WWPTF pt = WWobjtrans->WWgetScale();
    pt.x = pt.x * WWscaleX;
    pt.y = pt.y * WWscaleY;
    return pt;
}

WWBOOL WWrenderUnit::WWsetUnitStr(WWText* WWsrc)
{
    if (WWobjtrans == nullptr)
    {
        WWDEBUG("�����δ����transform������޷�����Ⱦ��Ҳ��Ӧ�ñ�����ͼԪ����");
        WWLOG("�����δ����transform������޷�����Ⱦ��Ҳ��Ӧ�ñ�����ͼԪ����");
        return false;
    }
    WWclear();
    WWtext = WWsrc;
    WWunitType = WW_SEL_STR;
    return true;
}

WWBOOL WWrenderUnit::WWsetUnitBit(WWBitmap* WWsrc)
{
    if (WWobjtrans == nullptr)
    {
        WWDEBUG("�����δ����transform������޷�����Ⱦ��Ҳ��Ӧ�ñ�����ͼԪ����");
        WWLOG("�����δ����transform������޷�����Ⱦ��Ҳ��Ӧ�ñ�����ͼԪ����");
        return false;
    }
    WWclear();
    WWbit = WWsrc;
    WWunitType = WW_SEL_BIT;
    return true;
}

WWBOOL WWrenderUnit::WWsetUnitGraph(WWGraph* WWsrc)
{
    if (WWobjtrans == nullptr)
    {
        WWDEBUG("�����δ����transform������޷�����Ⱦ��Ҳ��Ӧ�ñ�����ͼԪ����");
        WWLOG("�����δ����transform������޷�����Ⱦ��Ҳ��Ӧ�ñ�����ͼԪ����");
        return false;
    }
    WWclear();
    WWgra = WWsrc;
    WWunitType = WWsrc->type;
    if (WWsrc->type == WW_SEL_LINE)
    {
        WWPT tmp = WWgetGloblePt();
        WWsrc->pt1.x -= tmp.x;
        WWsrc->pt2.x -= tmp.x;
        WWsrc->pt1.y -= tmp.y;
        WWsrc->pt2.y -= tmp.y;
    }
    else if (WWsrc->type == WW_SEL_CIRCLE)
    {
        WWPT tmp = WWgetGloblePt();
        WWsrc->pt1.x -= tmp.x;
        WWsrc->pt1.y -= tmp.y;
    }
    else if (WWsrc->type == WW_SEL_RECT)
    {
        WWPT tmp = WWgetGloblePt();
        WWsrc->pt1.x -= tmp.x;
        WWsrc->pt2.x -= tmp.x;
        WWsrc->pt1.y -= tmp.y;
        WWsrc->pt2.y -= tmp.y;
    }
    return true;
}

WWBOOL WWrenderUnit::WWsetUnitAnimat(WWAnimation* WWsrc)
{
    if (WWobjtrans == nullptr)
    {
        WWDEBUG("�����δ����transform������޷�����Ⱦ��Ҳ��Ӧ�ñ�����ͼԪ����");
        WWLOG("�����δ����transform������޷�����Ⱦ��Ҳ��Ӧ�ñ�����ͼԪ����");
        return false;
    }
    WWclear();
    WWani = WWsrc;
    WWunitType = WW_SEL_ANI;
    WWaniTime = 0;
    WWaniAct = true;
    return true;
}

void WWrenderUnit::WWflushAnimat()
{
    WWaniTime = 0;
}

void WWrenderUnit::WWstopAnimat()
{
    WWaniAct = false;
}

void WWrenderUnit::WWbeginAnimat()
{
    WWaniAct = true;
}

void WWrenderUnit::WWclear()
{
    WWDELETE(WWbrush);
    WWDELETE(WWformat);
    WWDELETE(WWtext);
    WWDELETE(WWbit);
    WWDELETE(WWgra);
    WWDELETE(WWani);
    WWunitType = WW_SEL_EMPTY;
}

void WWrenderUnit::WWinit()
{
}

void WWrenderUnit::WWinit(WWobject* father)
{
    WWobjtrans = (WWtransform*)father->WWgetMoudule("transform");
    if (WWobjtrans == nullptr)
    {
        std::string str = "����ȾͼԪ�������ʧ�ܣ��丸���󲻴���transform���,����ID��" + std::to_string(father->WWgetID());
        WWDEBUG(str.c_str());
        WWLOG(str.c_str());
    }
}


void WWrenderUnit::WWsave(FILE* p)
{
}

void WWrenderUnit::WWupdate()
{
    if (WWunitType == WW_SEL_EMPTY)return;
    else if (WWunitType == WW_SEL_STR)
    {
        pt1 = WWgetGloblePt();
        WWdrawRect.left = pt1.x;
        WWdrawRect.top = pt1.y;
        WWdrawRect.bottom = WWdrawRect.top + WWtext->size;
        WWdrawRect.right = pt1.x + WWtextLayout->GetMaxWidth();
    }
    else if (WWunitType == WW_SEL_LINE)
    {
        pt1 = pt2 = WWgetGloblePt();
        pt1.x += WWgra->pt1.x;
        pt1.y += WWgra->pt1.y;
        pt2.x += WWgra->pt2.x;
        pt2.y += WWgra->pt2.y;
        WWdrawRect.left = min(pt1.x, pt2.x);
        WWdrawRect.top = min(pt1.y, pt2.y);
        WWdrawRect.bottom = max(pt1.x, pt2.x);
        WWdrawRect.right = max(pt1.y, pt2.y);
    }
    else if (WWunitType == WW_SEL_RECT)
    {
        pt1 = pt2 = WWgetGloblePt();
        pt1.x += WWgra->pt1.x;
        pt1.y += WWgra->pt1.y;
        pt2.x += WWgra->pt2.x;
        pt2.y += WWgra->pt2.y;
        WWdrawRect.left = min(pt1.x, pt2.x);
        WWdrawRect.top = min(pt1.y, pt2.y);
        WWdrawRect.bottom = max(pt1.x, pt2.x);
        WWdrawRect.right = max(pt1.y, pt2.y);
    }
    else if (WWunitType == WW_SEL_CIRCLE)
    {
        pt1 = WWgetGloblePt();
        pt1.x += WWgra->pt1.x;
        pt1.y += WWgra->pt1.y;
        WWdrawRect.left = pt1.x - WWgra->pt2.x;
        WWdrawRect.top = pt1.y - WWgra->pt2.y;
        WWdrawRect.bottom = pt1.x + WWgra->pt2.x;
        WWdrawRect.right = pt1.y + WWgra->pt2.y;
    }
    else if (WWunitType == WW_SEL_BIT)
    {
        pt1 = WWgetGloblePt();
        WWdrawRect.left = pt1.x;
        WWdrawRect.top = pt1.y;
        WWdrawRect.bottom = pt1.x + WWbit->size.x;
        WWdrawRect.right = pt1.y + WWbit->size.y;
    }
    else if (WWunitType == WW_SEL_ANI)
    {
        pt1 = WWgetGloblePt();
        WWdrawRect.left = pt1.x;
        WWdrawRect.top = pt1.y;
        WWdrawRect.bottom = pt1.x + WWani->size.x;
        WWdrawRect.right = pt1.y + WWani->size.y;
    }
    WWrenderer::WWaddUnit(this);
}

void WWrenderUnit::WWload(FILE* p)
{
}

WWBOOL WWrenderUnit::WWcreateDevRes()
{
    ID2D1HwndRenderTarget* target = WWrenderer::WWgetTar();
    HRESULT hr = S_FALSE;
    if (target == nullptr)
    {
        WWDEBUG("����ȾͼԪ�������ʧ�ܣ���Ⱦ�����ص��豸Ϊ��");
        WWLOG("����ȾͼԪ�������ʧ�ܣ���Ⱦ�����ص��豸Ϊ��");
        hr = E_FAIL;
    }
    if (WWunitType == WW_SEL_STR)
    {

        IDWriteFactory* writeFac = WWrenderer::WWgetWriteFac();
        if (writeFac == nullptr)
        {
            WWDEBUG("����ȾͼԪ�������ʧ�ܣ���Ⱦ�����ص��豸Ϊ��");
            WWLOG("����ȾͼԪ�������ʧ�ܣ���Ⱦ�����ص��豸Ϊ��");
            hr = E_FAIL;
        }
        if (WWtext == nullptr)
        {
            std::string s;
            s = "�����������Ϊ�ı�ͼԪ���������ı�ͼԪ��Ϣ���ڴ���,�����ţ�" + std::to_string(this->WWgetModuleID());
            WWDEBUG(s.c_str());
            WWLOG(s.c_str());
            hr = E_FAIL;
        }
        if (SUCCEEDED(hr))
        {
            hr = target->CreateSolidColorBrush(D2D1::ColorF(WWtext->col, 1.0), &WWbrush);
        }
        if (SUCCEEDED(hr))
        {
            hr = writeFac->CreateTextFormat(
                WWtext->font,
                NULL,
                DWRITE_FONT_WEIGHT_NORMAL,
                DWRITE_FONT_STYLE_NORMAL,
                DWRITE_FONT_STRETCH_NORMAL,
                WWtext->size * 96.0f / 72.0f,
                L"en_US",
                &WWformat
            );
        }
        if (SUCCEEDED(hr))
        {
            hr = writeFac->CreateTextLayout(
                WWtext->str,
                wcslen(WWtext->str),
                WWformat,
                0,
                WWtext->size,
                &WWtextLayout
            );
            FLOAT tmp;
            WWtextLayout->DetermineMinWidth(&tmp);
            WWtextLayout->SetMaxWidth(tmp);
            
        }
    }
    else if (WWunitType == WW_SEL_RECT|| WWunitType == WW_SEL_LINE || WWunitType == WW_SEL_CIRCLE)
    {
        if (WWgra == nullptr)
        {
            std::string s;
            s = "�����������Ϊ����ͼԪ�����������ͼԪ��Ϣ���ڴ���,�����ţ�" + std::to_string(this->WWgetModuleID());
            WWDEBUG(s.c_str());
            WWLOG(s.c_str());
            hr = E_FAIL;
        }
        if (SUCCEEDED(hr))
        {
            hr = target->CreateSolidColorBrush(
                D2D1::ColorF(WWgra->col, 1.0),
                &WWbrush);
        }
    }
    if (!SUCCEEDED(hr))
    {
        WWDEBUG("����豸����ʧ��");
        WWLOG("����豸����ʧ��");
        return false;
    }
    else
    {
        return true;
    }
}

void WWrenderUnit::WWrender()
{
    if (!WWnewSrc)
    {
        if (WWcreateDevRes())
        {
            WWnewSrc = false;
        }
        else
        {
            std::string s = "�����������Ⱦ��Դʧ�ܣ������ţ�" + std::to_string(WWgetModuleID());
            WWDEBUG(s.c_str());
            WWLOG(s.c_str());
            return;
        }
    }
    ID2D1HwndRenderTarget* target = WWrenderer::WWgetTar();
    if (target == nullptr)
    {
        std::string s = "�������Ⱦʧ�ܣ���Ⱦ�����ص��豸Ϊ�գ������ţ�" + std::to_string(WWgetModuleID());
        WWDEBUG(s.c_str());
        WWLOG(s.c_str());
        return;
    }
    WWPT tmpCenter = WWgetCenter();
    D2D1::Matrix3x2F mat1= D2D1::Matrix3x2F::Rotation(WWgetGlobleRotate(), WWcamera::WWtransPt(tmpCenter));
    WWPTF tmpScale = WWgetGlobleScale();
    D2D1::Matrix3x2F mat2 = D2D1::Matrix3x2F::Scale(D2D1::SizeF(tmpScale.x, tmpScale.y), WWcamera::WWtransPt(tmpCenter));
    D2D1::Matrix3x2F transMat;
    transMat.SetProduct(mat1, mat2);
    target->SetTransform(transMat);
    if (WWunitType == WW_SEL_LINE)
    {
        target->DrawLine(WWcamera::WWtransPt(pt1), WWcamera::WWtransPt(pt2), WWbrush, WWgra->wide);
    }
    else if (WWunitType == WW_SEL_CIRCLE)
    {
        if (!WWgra->fill)target->DrawEllipse(WWcamera::WWgetEllipse(pt1, pt2), WWbrush, WWgra->wide);
        else target->FillEllipse(WWcamera::WWgetEllipse(pt1, pt2), WWbrush);
    }
    else if (WWunitType == WW_SEL_RECT)
    {
        if (!WWgra->fill)target->DrawRectangle(WWcamera::WWgetRect(pt1, pt2), WWbrush, WWgra->wide);
        else target->FillRectangle(WWcamera::WWgetRect(pt1, pt2), WWbrush);
    }
    else if (WWunitType == WW_SEL_STR)
    {
        target->DrawTextLayout(
            WWcamera::WWtransPt(pt1),
            WWtextLayout,
            WWbrush
        );
        //target->DrawTextW(WWtext->str,
        //    wcslen(WWtext->str),
        //    WWformat,
        //    WWcamera::WWtransRect(WWdrawRect),
        //    WWbrush
        //);
    }
    else if (WWunitType == WW_SEL_BIT || WWunitType == WW_SEL_ANI)
    {
        target->DrawBitmap(
            WWbit->bitsrc,
            WWcamera::WWtransRect(WWdrawRect),
            1.0,
            D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
            WWcamera::WWgetRect(WWbit->offpos, WWbit->size.x, WWbit->size.y)
        );
    }
}

WWPT WWrenderUnit::WWgetCenter()
{
    WWPT tmp = WWgetGloblePt();
    tmp.x += WWcenter.x;
    tmp.y += WWcenter.y;
    return tmp;
}
