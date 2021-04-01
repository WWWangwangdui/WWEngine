#pragma once
#include<afx.h>
#include"WWdefine.h"
#include"WWobject.h"
class WWobject;
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

