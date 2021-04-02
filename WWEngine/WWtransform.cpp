#include "WWtransform.h"
#include"WWcamera.h"

WWtransform::WWtransform()
{
	WWposX=0, WWposY=0;

	WWrotate=0;

	WWscaleX = 1.0;
	WWscaleY = 1.0;

	WWfollow = false;
	
	WWfollowrate = 1.0f;
	WWmoduleName = "transform";
	WWactivity = true;
}

void WWtransform::WWsetPoint(WWINT x, WWINT y)
{
	WWposX = x;
	WWposY = y;
}

WWPT WWtransform::WWgetPos()
{
	WWPT tmp;
	tmp.x = WWposX;
	tmp.y = WWposY;
	return tmp;
}

WWPTF WWtransform::WWgetScale()
{
	return WWPTF{ WWscaleX,WWscaleY };
}

WWINT WWtransform::WWgetRotate()
{
	return WWrotate;
}

void WWtransform::WWsetRotate(WWINT rotate)
{
	WWrotate = rotate;
}

void WWtransform::WWsetScale(WWFLOAT scaleX, WWFLOAT scaleY)
{
	WWscaleX = scaleX;
	WWscaleY = scaleY;
}

void WWtransform::WWmove(WWINT dx, WWINT dy)
{
	WWposX += dx;
	WWposY += dy;
}

void WWtransform::WWinit()
{

}


void WWtransform::WWsave(FILE* fp)
{
	//fprintf(fp, "%d %d %d %d", WWposX, WWposY, WWrotate, WWscale);
}

void WWtransform::WWupdate()
{
	if (WWfollow)
	{
		WWcamera::WWaddFollow(this);
	}
}

void WWtransform::WWload(FILE* fp)
{
}

WWFLOAT WWtransform::WWgetFollowRate()
{
	return WWfollowrate;
}
