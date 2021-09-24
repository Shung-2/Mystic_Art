#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}

playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init(true);
	
	/* SHIP 수업 내용 */
	//IMAGEMANAGER->addImage("배경", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//_ship = new spaceShip;
	//_ship->init();

	//IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("enemy", "ufo.bmp", 0, 0, 530, 32, 10, 1, true, RGB(255, 0, 255));

	/* SCENE 추가 */
	SCENEMANAGER->addScene("INTRO", new testScene);
	SCENEMANAGER->addScene("OPTION", new testScene2);
	SCENEMANAGER->addScene("STAGE 1", new Stage1);
	SCENEMANAGER->addScene("STAGE 2", new Stage2);
	SCENEMANAGER->addScene("STAGE 3", new Stage3);
	SCENEMANAGER->changeScene("INTRO");

	/* STAGE 동적할당 */
	st = new Stage1;
	st->setPlayerAddressLink(pl);

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();

	//SAFE_DELETE(_ship);
}

void playGround::update()
{
	gameNode::update();

	//_ship->update();

	/* 특정 키를 입력 할 때 씬 전환 */
	SCENEMANAGER->update();	

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("STAGE 1");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("STAGE 2");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene("STAGE 3");
	}
}

void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	//IMAGEMANAGER->findImage("배경")->render(getMemDC(), 0, 0);	
	//_ship->render();

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());
	
	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
