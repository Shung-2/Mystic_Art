#include "stdafx.h"
#include "testScene2.h"

testScene2::testScene2()
{
}

testScene2::~testScene2()
{
}

HRESULT testScene2::init()
{
	//IMAGEMANAGER->addImage("¸»", "¸».bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Intro Mystic Arts LOGO", "cnx/! intro/bmp/mystic arts.bmp", 600, 317, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Intro Coin Character LOGO", "cnx/! intro/bmp/Coin Character Logo.bmp", 424, 424, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Intro After KeyPress BG", "cnx/! intro/bmp/intro bg keypress.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	/* RECT */
	_Intro_MysticArtsLogo = RectMakeCenter(WINSIZEX / 2 - 225, WINSIZEY / 2 - 220, 100, 100);
	_Intro_CoinCharacterLogo = RectMakeCenter(WINSIZEX / 2 - 50, ((WINSIZEY / 2) / 2) + 100, 320, 320);

	return S_OK;
}

void testScene2::release()
{
}

void testScene2::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SCENEMANAGER->changeScene("INTRO");
	}
}

void testScene2::render()
{
	// IMAGEMANAGER->findImage("¸»")->render(getMemDC());

	IMAGEMANAGER->findImage("Intro After KeyPress BG")->render(getMemDC());
	IMAGEMANAGER->findImage("Intro Coin Character LOGO")->render(getMemDC(), _Intro_CoinCharacterLogo.left, _Intro_CoinCharacterLogo.top);
	IMAGEMANAGER->findImage("Intro Mystic Arts LOGO")->render(getMemDC(), _Intro_MysticArtsLogo.left, _Intro_MysticArtsLogo.top);
}
