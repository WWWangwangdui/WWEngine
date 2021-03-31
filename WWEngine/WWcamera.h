#pragma once
#include"WWdefine.h"
#include"WWobject.h"
class WWcamera
{
private:
	WWINT WWwide;
	WWINT WWheight;
	WWINT WWposX;
	WWINT WWposY;
public:
	WWcamera();
	~WWcamera();
	WWBOOL WWcheckInCamera(CRect rect);
	void WWlookAt(WWobject& obj);
	void WWstSize(WWINT wide, WWINT height);
	void WWsetPos(WWINT posX, WWINT posY);
	void WWtransPt(WWPT& srcpt, WWPT& despt);
};

