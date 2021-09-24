#include "stdafx.h"
#include "Stage1.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

HRESULT Stage1::init()
{
	IMAGEMANAGER->addImage("Stage 1 BG", "cnx/! stage/bg/final edit stg1.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage 1-2 BG", "cnx/! stage/bg/final edit stg1-2.bmp", 1600, 900, true, RGB(255, 0, 255));

	/* STGAE1 OBJ RECT 크기 설정 */
	_Stage1_Obj[0] = RectMake(118, 295, 565, 65);
	_Stage1_Obj[1] = RectMake(78, 570, 720, 65);
	_Stage1_Obj[2] = RectMake(880, 140, 675, 65);
	_Stage1_Obj[3] = RectMake(965, 420, 550, 65);

	/* STGAE1 Rand RECT 크기 설정 */
	_Stage1_Rand[0] = RectMake(0, WINSIZEY - 60, WINSIZEX, 75);
	_Stage1_Rand[1] = RectMake(WINSIZEX / 2 + 40, WINSIZEY / 2 + 330, 800, 60);
	_Stage1_Rand[2] = RectMake(WINSIZEX / 2 + 280, WINSIZEY / 2 + 270, 520, 60);

	/* PLAYER 동적 할당 */
	_Player = new Player;
	_Player->init();

	return S_OK;
}

void Stage1::release()
{
	SAFE_DELETE(_Player);
}

void Stage1::update()
{
	_Player->update();

	/* STAGE1 RAND 충돌 */
	for (int i = 0; i < 3; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_Stage1_Rand[i], &_Player->getTagPlayer()->_rc))
		{
			if (_Player->getTagPlayer()->_rc.bottom > _Stage1_Rand[i].top &&
				_Player->getTagPlayer()->_rc.top <= _Stage1_Rand[i].top)
			{
				_Player->getTagPlayer()->_isJump = false;
				_Player->getTagPlayer()->_isLanding = true;
				_Player->getTagPlayer()->_jumpPower = 0.0f;

				_Player->getTagPlayer()->_y = _Stage1_Rand[i].top - 25;
			}
		}
	}

	/* STAGE1 OBJ 충돌 */
	for (int i = 0; i < 5; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_Stage1_Obj[i], &_Player->getTagPlayer()->_rc))
		{
			// UP
			if (_Stage1_Obj[i].top > _Player->getTagPlayer()->_y &&
				_Stage1_Obj[i].left < _Player->getTagPlayer()->_x &&
				_Stage1_Obj[i].right > _Player->getTagPlayer()->_x)
			{
				_Player->getTagPlayer()->_jumpPower -= 0.01f;
				if (_Player->getTagPlayer()->_jumpPower >= 0) break;
				_Player->getTagPlayer()->_jumpPower = 0.0f;

				_Player->getTagPlayer()->_y = _Stage1_Obj[i].top - 30;
				
				_Player->getTagPlayer()->_isLanding = true;
				_Player->getTagPlayer()->_isJump = false;
			}

			// DOWN JUMP
			if (_Stage1_Obj[i].top > _Player->getTagPlayer()->_y &&
				_Stage1_Obj[i].left < _Player->getTagPlayer()->_x &&
				_Stage1_Obj[i].right > _Player->getTagPlayer()->_x &&
				_Player->getTagPlayer()->_isDownJump == true)
			{
				_Player->getTagPlayer()->_y = _Stage1_Obj[i].top + 10;
				_Player->getTagPlayer()->_isJump = true;
				_Player->getTagPlayer()->_isDownJump = false;
				_Player->getTagPlayer()->_isLanding = false;
			}
		}		
	}
}

void Stage1::render()
{
	IMAGEMANAGER->findImage("Stage 1-2 BG")->render(getMemDC());

	/* STAGE1 RAND RECT 출력 */
	//for (int i = 0; i < 4; i++)
	//{
	//	Rectangle(getMemDC(), _Stage1_Obj[i]);
	//}

	////* STAGE1 OBJ RECT 출력 */
	//for (int i = 0; i < 3; i++)
	//{
	//	Rectangle(getMemDC(), _Stage1_Rand[i]);
	//}

	_Player->render();
}