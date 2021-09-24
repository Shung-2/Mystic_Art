#include "stdafx.h"
#include "pixelCollision.h"

pixelCollision::pixelCollision()
{
}

pixelCollision::~pixelCollision()
{
}

HRESULT pixelCollision::init()
{
	//IMAGEMANAGER->addImage("Stage 1 BG", "cnx/! stage/bg/final edit stg1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	//_Player = new Player;
	//_Player->init();

	return S_OK;
}

void pixelCollision::release()
{
	//SAFE_DELETE(_Player);
}

void pixelCollision::update()
{
	_Player->getTagPlayer()->_probeY = _Player->getTagPlayer()->_y + _Player->getTagPlayer()->_Player_img->getHeight() / 2;

	for (int i = _Player->getTagPlayer()->_probeY - 50; i < _Player->getTagPlayer()->_probeY + 50; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("Stage 1 BG")->getMemDC(), _Player->getTagPlayer()->_x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		
		if (!(r == 255 && g == 0 && b == 255))
		{
			_Player->getTagPlayer()->_y = i - _Player->getTagPlayer()->_Player_img->getHeight() / 2;
			break;
		}
	}
	//_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
}

void pixelCollision::render()
{
	//IMAGEMANAGER->findImage("STAGE 1 BG")->render(getMemDC());
	//_ball->render(getMemDC(), _rc.left, _rc.top);

}
