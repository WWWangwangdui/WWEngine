#include "WWcamera.h"
#include"WWobject.h"
#include"WWtransform.h"
#include"WWwindow.h"
WWINT WWcamera::WWwide = 900;
WWINT WWcamera::WWheight = 600;
WWINT WWcamera::WWposX = 0;
WWINT WWcamera::WWposY = 0;
WWINT WWcamera::WWlastPosX = 0;
WWINT WWcamera::WWlastPosY = 0;
std::vector<WWtransform*>WWcamera::WWfollowList;

WWBOOL WWcamera::WWcheckInCamera(CRect& rect)
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
	WWtransform* trans;
	trans = (WWtransform*)obj.WWgetMoudule("transform");
	if (trans == nullptr)
	{
		WWDEBUG("该指定的对象不存在transform组件，镜头锁定失败");
		WWLOG("该指定的对象不存在transform组件，镜头锁定失败");
		return;
	}
	WWposX = trans->WWgetPos().x;
	WWposY = trans->WWgetPos().y;
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

D2D1_POINT_2F WWcamera::WWtransPt(WWPT& srcpt)
{
	return D2D1::Point2F(srcpt.x + WWposX, srcpt.y + WWposY);
}

D2D1_RECT_F WWcamera::WWgetRect(WWPT& pt1, WWPT& pt2)
{
	return D2D1::RectF(pt1.x + WWposX, pt1.y + WWposY, pt2.x + WWposX, pt2.y + WWposY);
}

D2D1_ELLIPSE WWcamera::WWgetEllipse(WWPT& pt1, WWPT& pt2)
{
	return D2D1::Ellipse(WWtransPt(pt1), pt2.x, pt2.y);
}

D2D1_RECT_F WWcamera::WWtransRect(RECT& rec)
{
	return D2D1::RectF(rec.left, rec.top, rec.right, rec.bottom);
}

D2D1_RECT_F WWcamera::WWgetRect(WWPT& pt1, LONG wide, LONG height)
{
	return D2D1::RectF(pt1.x, pt1.y, pt1.x + wide, pt1.y + height);
}

void WWcamera::WWaddFollow(WWtransform* src)
{
	WWfollowList.push_back(src);
}

void WWcamera::WWonFollow()
{
	WWINT dx = WWposX - WWlastPosX;
	WWINT dy = WWposY - WWlastPosY;
	for (auto it : WWfollowList)
	{
		it->WWmove(dx * it->WWgetFollowRate(), dy * it->WWgetFollowRate());
	}
	WWfollowList.clear();
}
