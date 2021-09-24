#include "stdafx.h"
#include "Stage2.h"

Stage2::Stage2()
{
}

Stage2::~Stage2()
{
}

HRESULT Stage2::init()
{
	IMAGEMANAGER->addImage("Stage 2 BG", "cnx/! stage/bg/final edit stg2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	/* STGAE2 OBJ RECT 크기 설정 */
	_Stage2_Obj[0] = RectMake(0, 133, 315, 65);
	_Stage2_Obj[1] = RectMake(WINSIZEX / 2 + 485, 133, 315, 65);
	_Stage2_Obj[2] = RectMake(WINSIZEX / 2 - 565, 350, 315, 65);
	_Stage2_Obj[3] = RectMake(WINSIZEX / 2 + 250, 350, 315, 65);
	_Stage2_Obj[4] = RectMake(WINSIZEX / 2 - 320, WINSIZEY / 2 + 140, 635, 65);

	/* STGAE2 Rand RECT 크기 설정 */
	_Stage2_Rand = RectMake(0, WINSIZEY - 60, WINSIZEX, 75);

	/* PLAYER 동적 할당 */
	_Player = new Player;
	_Player->init();

	return S_OK;
}

void Stage2::release()
{
	SAFE_DELETE(_Player);
}

void Stage2::update()
{
	_Player->update();

	/* STAGE2 RAND 충돌 */

	if (_Player->getTagPlayer()->_rc.bottom > _Stage2_Rand.top &&
		_Player->getTagPlayer()->_rc.top <= _Stage2_Rand.top)
	{
		_Player->getTagPlayer()->_isJump = false;
		_Player->getTagPlayer()->_isLanding = true;

		_Player->getTagPlayer()->_jumpPower = 0.0f;

		_Player->getTagPlayer()->_y = _Stage2_Rand.top - 30;
	}

	/* STAGE2 OBJ 충돌 */
	for (int i = 0; i < 5; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_Stage2_Obj[i], &_Player->getTagPlayer()->_rc))
		{
			// UP
			if (_Stage2_Obj[i].top > _Player->getTagPlayer()->_y &&
				_Stage2_Obj[i].left < _Player->getTagPlayer()->_x &&
				_Stage2_Obj[i].right > _Player->getTagPlayer()->_x)
			{
				_Player->getTagPlayer()->_jumpPower -= 0.01f;
				if (_Player->getTagPlayer()->_jumpPower >= 0) break;
				_Player->getTagPlayer()->_jumpPower = 0.0f;

				_Player->getTagPlayer()->_y = _Stage2_Obj[i].top - 30;

				_Player->getTagPlayer()->_isLanding = true;
				_Player->getTagPlayer()->_isJump = false;
			}

			// DOWN JUMP
			if (_Stage2_Obj[i].top > _Player->getTagPlayer()->_y &&
				_Stage2_Obj[i].left < _Player->getTagPlayer()->_x &&
				_Stage2_Obj[i].right > _Player->getTagPlayer()->_x &&
				_Player->getTagPlayer()->_isDownJump == true)
			{
				_Player->getTagPlayer()->_y = _Stage2_Obj[i].top + 10;
				_Player->getTagPlayer()->_isJump = true;
				_Player->getTagPlayer()->_isDownJump = false;
				_Player->getTagPlayer()->_isLanding = false;

			}
		}
	}
}

void Stage2::render()
{
	IMAGEMANAGER->findImage("Stage 2 BG")->render(getMemDC());

	///* STAGE2 RAND RECT 출력 */
	//Rectangle(getMemDC(), _Stage2_Rand);

	///* STAGE2 OBJ RECT 출력 */
	//for (int i = 0; i < 5; i++)
	//{
	//	Rectangle(getMemDC(), _Stage2_Obj[i]);
	//}

	_Player->render();
}
