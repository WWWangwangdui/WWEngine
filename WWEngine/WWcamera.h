#pragma once
#include"WWtype.h"
class WWobject;
static class WWcamera
{
private:
	static WWINT WWwide;
	static WWINT WWheight;
	static WWINT WWposX;
	static WWINT WWposY;
	static WWINT WWlastPosX;
	static WWINT WWlastPosY;
	static std::vector<WWtransform*>WWfollowList;
public:
	static WWBOOL WWcheckInCamera(CRect& rect);
	static void WWlookAt(WWobject& obj);
	static void WWstSize(WWINT wide, WWINT height);
	static void WWsetPos(WWINT posX, WWINT posY);
	static void WWtransPt(WWPT& srcpt, WWPT& despt);
	static D2D1_POINT_2F WWtransPt(WWPT& srcpt);
	static D2D1_RECT_F WWgetRect(WWPT& pt1, WWPT& pt2);
	static D2D1_ELLIPSE WWgetEllipse(WWPT& pt1, WWPT& pt2);
	static D2D1_RECT_F WWtransRect(RECT& rec);
	static D2D1_RECT_F WWgetRect(WWPT& pt1, LONG wide, LONG height);
	static void WWaddFollow(WWtransform* src);
	static void WWonFollow();
};

