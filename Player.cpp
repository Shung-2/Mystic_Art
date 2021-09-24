#include "stdafx.h"
#include "Player.h"
#include "IdelState.h"

void Player::InputHandle()
{
	State* newState = _state->inputHandle(this);
	if (newState != nullptr)
	{
		SAFE_DELETE(_state);
		_state = newState;
		_state->enter(this);
	}
}

Player::Player()
{
}

Player::~Player()
{
}

HRESULT Player::init()
{
	/* IMG 동적 할당 */
	_player._Player_img = new image;
	IMAGEMANAGER->addFrameImage("PLAYER IDEL", "cnx/! player/bmp/idel.bmp", 320, 264, 4, 2, true, RGB(255, 0, 255));
	_player._Player_img = IMAGEMANAGER->findImage("PLAYER IDEL");

	/* INIT */
	set_Player();

	/* STATE PATTEN */
	_state = new IdelState();
	_state->enter(this);

	return S_OK;
}

void Player::release()
{
}

void Player::update()
{
	_player._probeY = _player._y;

	/* 상태 패턴 */
	InputHandle();
	_state->update(this);

	/* COLLISION */
	On_Screen();
	pixelCollision();

	/* RE_RENDER (충돌렉트 & 이미지렉트) */
	_player._rc = RectMakeCenter(_player._x, _player._y, 30, 65);
	_player._rcimg = RectMakeCenter(_player._x, _player._y, 80, 190);
}

void Player::render()
{
	_player._Player_img->frameRender(getMemDC(), _player._rcimg.left, _player._rcimg.top);
	Rectangle(getMemDC(), _player._rc);
}

void Player::set_Player()
{
	_player._rc = RectMakeCenter(WINSIZEX / 2 - 250, WINSIZEY / 2 + 365, 30, 65);
	_player._x = (_player._rc.right + _player._rc.left) / 2;
	_player._y = (_player._rc.bottom + _player._rc.top) / 2;
	_player._height = (_player._rc.bottom - _player._rc.top);
	_player._probeY = _player._y;
	_player._speed = 5;
	_player._jumpCount = 0;
	_player._grvity = 0.5f;

	_player._isJump = false;
	_player._isDownJump = false;
	_player._dir = true;
	_player._isLanding = false;

	/* PLAYER IMAGE */
	IMAGEMANAGER->addFrameImage("PLAYER RUN", "cnx/! player/bmp/run.bmp", 1188, 268, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PLAYER JUMP", "cnx/! player/bmp/jump.bmp", 500, 352, 5, 2, true, RGB(255, 0, 255));
}

void Player::pixelCollision()
{
	for (int i = _player._probeY - _player._height / 2; i < _player._probeY + _player._height / 2; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("Stage 1 BG")->getMemDC(), _player._x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if((r == 255 && g == 0 && b == 255))
		{
			_player._y = i - _player._height / 2;
			//_player._grvity = 0.0f;
			_player._jumpPower = 0.0f;
			_player._isLanding = true;
			//_player._isPixelLanding = true;
			break;
		}
	}
	_player._rc = RectMake(_player._x, _player._y, _player._Player_img->getWidth() / 7, _player._Player_img->getHeight() / 4);
}

void Player::On_Screen()
{	
	/* SCREEN LOCK */
	/* LEFT */
	if (_player._x < 0)
	{
		_player._x += _player._speed;
	}

	/* RIGHT */
	if (_player._x > WINSIZEX)
	{
		_player._x -= _player._speed;
	}

	/* UP */
	if (_player._y < 0)
	{
		_player._y -= _player._jumpPower;
	}
}
