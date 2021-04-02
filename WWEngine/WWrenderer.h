#pragma once
#include"WWtype.h"
class WWcamera;
class WWrenderUnit;
static class WWrenderer
{
private:
	static HWND m_hwnd;
	static WWcamera camera;
	static std::vector<WWrenderUnit*>renderlist;
	static ID2D1Factory* fac;
	static ID2D1HwndRenderTarget* rendertarget;
	static IDWriteFactory* writefac;
	static WWBOOL createTarget();
public:
	~WWrenderer();
	static void WWinit(HWND hwnd);
	static void update();
	static void WWreSize();
	static ID2D1Factory* WWgetFac();
	static IDWriteFactory* WWgetWriteFac();
	static ID2D1HwndRenderTarget* WWgetTar();
	static void WWaddUnit(WWrenderUnit* unit);
};

