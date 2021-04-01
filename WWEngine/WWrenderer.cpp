#include "WWrenderer.h"

HWND WWrenderer::m_hwnd = NULL;
WWcamera WWrenderer::camera;
std::vector<WWrenderUnit>WWrenderer::renderlist;
ID2D1Factory* WWrenderer::fac = nullptr;
ID2D1HwndRenderTarget* WWrenderer::rendertarget = nullptr;
IDWriteFactory* WWrenderer::writefac = nullptr;

WWrenderer::~WWrenderer()
{
	WWRELEASE(&fac);
	WWRELEASE(&writefac);
	WWRELEASE(&rendertarget);
}

void WWrenderer::init(HWND hwnd)
{
	m_hwnd = hwnd;
	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &fac);
	DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(writefac), reinterpret_cast<IUnknown**>(&writefac));
}

void WWrenderer::update()
{
	if (rendertarget == nullptr)
	{
		if (!createTarget())
		{
			WWERROR("创建绘图设备失败");
			WWLOG("创建绘图设备失败");
			return;
		}
	}
	rendertarget->BeginDraw();
	rendertarget->Clear(D2D1::ColorF(255, 255, 255, 1));
	ID2D1SolidColorBrush* br;
	rendertarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::LightSlateGray),
		&br
	);
	rendertarget->DrawLine(D2D1::Point2(1, 1), D2D1::Point2(500, 500), br);

	rendertarget->EndDraw();
}

void WWrenderer::WWreSize()
{
	if (rendertarget)
	{
		RECT rc;
		GetClientRect(m_hwnd, &rc);
		rendertarget->Resize(D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top));
	}
}

WWBOOL WWrenderer::createTarget()
{
	RECT rc;
	GetClientRect(m_hwnd, &rc);
	D2D1_SIZE_U size = D2D1::SizeU(
		rc.right - rc.left,
		rc.bottom - rc.top
	);
	auto it1 = D2D1::RenderTargetProperties();
	auto it2 = D2D1::HwndRenderTargetProperties(m_hwnd, size);
	HRESULT hr= fac->CreateHwndRenderTarget(
		it1,
		it2,
		&rendertarget
	);
	if (rendertarget != nullptr)return true;
	DWORD tmp = GetLastError();
	return false;
}