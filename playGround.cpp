#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}

playGround::~playGround()
{
}

//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init(true);
	
	/* SHIP ���� ���� */
	//IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//_ship = new spaceShip;
	//_ship->init();

	//IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("enemy", "ufo.bmp", 0, 0, 530, 32, 10, 1, true, RGB(255, 0, 255));

	/* SCENE �߰� */
	SCENEMANAGER->addScene("INTRO", new testScene);
	SCENEMANAGER->addScene("OPTION", new testScene2);
	SCENEMANAGER->addScene("STAGE 1", new Stage1);
	SCENEMANAGER->addScene("STAGE 2", new Stage2);
	SCENEMANAGER->addScene("STAGE 3", new Stage3);
	SCENEMANAGER->changeScene("INTRO");

	/* STAGE �����Ҵ� */
	st = new Stage1;
	st->setPlayerAddressLink(pl);

	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();

	//SAFE_DELETE(_ship);
}

void playGround::update()
{
	gameNode::update();

	//_ship->update();

	/* Ư�� Ű�� �Է� �� �� �� ��ȯ */
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
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	//IMAGEMANAGER->findImage("���")->render(getMemDC(), 0, 0);	
	//_ship->render();

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());
	
	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
