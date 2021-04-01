#pragma once
#include<afx.h>
#include<vector>
#include"WWdefine.h"
#include"WWcamera.h"
#include"WWrenderUnit.h"
class WWcamera;
class WWrenderUnit;
static class WWrenderer
{
private:
	static HWND m_hwnd;
	static WWcamera camera;
	static std::vector<WWrenderUnit>renderlist;
	static ID2D1Factory* fac;
	static ID2D1HwndRenderTarget* rendertarget;
	static IDWriteFactory* writefac;
	static WWBOOL createTarget();
public:
	~WWrenderer();
	static void init(HWND hwnd);
	static void update();
	static void WWreSize();

};

