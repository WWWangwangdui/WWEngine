#include "WWcamera.h"

WWcamera::WWcamera()
{
	WWposX = WWposY = 0;
	WWwide = 900, WWheight = 600;
}

WWcamera::~WWcamera()
{

}

WWBOOL WWcamera::WWcheckInCamera(CRect rect)
{
	WWINT x1, x2, y1, y2;
	x1 = (WWposX + WWposX + WWwide - rect.left - rect.right);
	x2 = (WWwide + rect.right - rect.left);
	y1 = (WWposY + WWposY + WWheight - rect.bottom - rect.top);
	y2 = (WWheight + rect.bottom - rect.top);
	return x1 * x1 <= x2* x2 * 4 && y1 * y1 <= y2* y2 * 4;
}

void WWcamera::WWlookAt(WWobject& obj)
{
	//������
	/*transform* trans;
	trans = obj.WWgetMoudule(L"transform");
	if (trans == nullptr)
	{
		WWDEBUG("��ָ���Ķ��󲻴���transform�������ͷ����ʧ��");
		WWLOG("��ָ���Ķ��󲻴���transform�������ͷ����ʧ��");
	}
	WWposX=*/
}

void WWcamera::WWstSize(WWINT wide, WWINT height)
{
	WWwide = wide;
	WWheight = height;
}

void WWcamera::WWsetPos(WWINT posX, WWINT posY)
{
	WWposX = posX;
	WWposY = posY;
}

void WWcamera::WWtransPt(WWPT& srcpt, WWPT& despt)
{
	despt.x = srcpt.x - WWposX;
	despt.y = srcpt.y - WWposY;
}
