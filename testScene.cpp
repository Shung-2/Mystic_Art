#include "stdafx.h"
#include "testScene.h"

testScene::testScene()
{
}

testScene::~testScene()
{
}

HRESULT testScene::init()
{
	/* BOOL */
	_IntroBG_Black_To_BeforeKeyPressBG = true;
	_IntroBG_BeforeKeyPressBG_To_AfterKeyPressBG = false;
	_Print_TitleMenu = false;

	/* IMAGE */
	IMAGEMANAGER->addImage("Intro Black BG", "cnx/! intro/bmp/balck.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Intro Mystic Arts LOGO", "cnx/! intro/bmp/mystic arts.bmp", 600, 317, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Intro Before KeyPress BG", "cnx/! intro/bmp/intro bg.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Intro Coin Character LOGO", "cnx/! intro/bmp/Coin Character Logo.bmp", 424, 424, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Intro After KeyPress BG", "cnx/! intro/bmp/intro bg keypress.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));	
	IMAGEMANAGER->addImage("Intro TTL Menu ALL", "cnx/! title_menu/bmp/ttlmenu all.bmp", 400, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Intro GameStart Button", "cnx/! title_menu/bmp/game start.bmp", 372, 84, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Intro Option Button", "cnx/! title_menu/bmp/option.bmp", 225, 84, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Intro Exit Button", "cnx/! title_menu/bmp/exit.bmp", 132, 80, 1, 2, true, RGB(255, 0, 255));

	/* RECT */
	_Intro_MysticArtsLogo = RectMakeCenter(WINSIZEX / 2 - 225, WINSIZEY, 100, 100);
	_Intro_CoinCharacterLogo = RectMakeCenter(WINSIZEX / 2 - 50, ((WINSIZEY / 2) / 2) + 100, 320, 320);
	_Intro_TTLMenuAll = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 170, 400, 400);
	_Intro_TitleMenu[0] = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 96, 372, 84);
	_Intro_TitleMenu[1] = RectMakeCenter(WINSIZEX / 2 - 73, WINSIZEY / 2 + 180, 225, 84);
	_Intro_TitleMenu[2] = RectMakeCenter(WINSIZEX / 2 - 120, WINSIZEY / 2 + 274, 132, 80);
	
	/* CHOICE TITLE MENU */
	_TitleMenu_Index = 0;
	_Choice = GAME_START;
	_Choice_img = new image;
	_Choice_img = IMAGEMANAGER->findImage("Intro GameStart Button");

	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	/* �ΰ� ��ġ �̵� */
	_Intro_MysticArtsLogo.top		-= 10;
	_Intro_MysticArtsLogo.bottom	-= 10;

	/* ������ ��ġ�� �ΰ� ������ �� */
	if (_Intro_MysticArtsLogo.top <= 130)
	{
		_Intro_MysticArtsLogo.top		= 130;
		_Intro_MysticArtsLogo.bottom	= 130;
		_IntroBG_Black_To_BeforeKeyPressBG = false;

		/* �����̽� Ű�� �Է��ϸ� ���� ���� */
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_IntroBG_BeforeKeyPressBG_To_AfterKeyPressBG = true;
			_Print_TitleMenu = true;
		}
	}

	if (_Print_TitleMenu == true)
	{
		/* �ش� ��ư�� �� �̹��� ������ ��� */
		if (_Choice == GAME_START)
		{
			_Choice_img->setFrameY(1);
			_Choice_img->setFrameX(_TitleMenu_Index);
		}

		if (_Choice == OPTION)
		{
			_Choice_img->setFrameY(1);
			_Choice_img->setFrameX(_TitleMenu_Index);
		}

		if (_Choice == EXIT)
		{
			_Choice_img->setFrameY(1);
			_Choice_img->setFrameX(_TitleMenu_Index);
		}

		/* �������� ��ư ���� */
		if (_Choice == GAME_START && KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_Choice = OPTION;
		}

		if (_Choice == OPTION && KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_Choice = EXIT;
		}

		if (_Choice == EXIT && KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_Choice = OPTION;
		}

		if (_Choice == OPTION && KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_Choice = GAME_START;
		}

		/* ��ư�� ������ �� �����ϴ� �κ� */
		/* GAME START BUTTON PRESS */
		if (_Choice == GAME_START && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			SCENEMANAGER->changeScene("STAGE 1");
		}

		/* OPTION BUTTON PRESS */
		if (_Choice == OPTION && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			SCENEMANAGER->changeScene("OPTION");
		}

		/* EXIT BUTTON PRESS */
		if (_Choice == EXIT && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			PostQuitMessage(0);
		}
	}
}

void testScene::render()
{
	/* �ΰ� ���� �� ����ȭ���� �� */
	if (_IntroBG_Black_To_BeforeKeyPressBG == true)
	{
		IMAGEMANAGER->findImage("Intro Black BG")->render(getMemDC());
		IMAGEMANAGER->findImage("Intro Mystic Arts LOGO")->render(getMemDC(), _Intro_MysticArtsLogo.left, _Intro_MysticArtsLogo.top);
	}
	else
	{
		/* �ΰ� ���� ��, Ű ������ �� �Ϲ�ȭ�� �� �� */
		IMAGEMANAGER->findImage("Intro Before KeyPress BG")->render(getMemDC());
		IMAGEMANAGER->findImage("Intro Coin Character LOGO")->render(getMemDC(), _Intro_CoinCharacterLogo.left, _Intro_CoinCharacterLogo.top);
		IMAGEMANAGER->findImage("Intro Mystic Arts LOGO")->render(getMemDC(), _Intro_MysticArtsLogo.left, _Intro_MysticArtsLogo.top);

		/* �ƹ�Ű�� ������ �� ���� ȭ���� �� */
		if (_IntroBG_BeforeKeyPressBG_To_AfterKeyPressBG == true)
		{
			IMAGEMANAGER->findImage("Intro After KeyPress BG")->render(getMemDC());
			IMAGEMANAGER->findImage("Intro Coin Character LOGO")->render(getMemDC(), _Intro_CoinCharacterLogo.left, _Intro_CoinCharacterLogo.top);
			IMAGEMANAGER->findImage("Intro Mystic Arts LOGO")->render(getMemDC(), _Intro_MysticArtsLogo.left, _Intro_MysticArtsLogo.top);

			/* �ƹ�Ű�� ������ �� ���� Ÿ��Ʋȭ�� �޴� ��� */
			if (_Print_TitleMenu == true)
			{
				IMAGEMANAGER->findImage("Intro TTL Menu ALL")->render(getMemDC(), _Intro_TTLMenuAll.left, _Intro_TTLMenuAll.top);

				if (_Choice == GAME_START)
				{
					_Choice_img = IMAGEMANAGER->findImage("Intro GameStart Button");
					_Choice_img->frameRender(getMemDC(), _Intro_TitleMenu[0].left, _Intro_TitleMenu[0].top);
				}

				if (_Choice == OPTION)
				{
					_Choice_img = IMAGEMANAGER->findImage("Intro Option Button");
					_Choice_img->frameRender(getMemDC(), _Intro_TitleMenu[1].left, _Intro_TitleMenu[1].top);
				}

				if (_Choice == EXIT)
				{
					_Choice_img = IMAGEMANAGER->findImage("Intro Exit Button");
					_Choice_img->frameRender(getMemDC(), _Intro_TitleMenu[2].left, _Intro_TitleMenu[2].top);
				}
			}
		}
	}	
}