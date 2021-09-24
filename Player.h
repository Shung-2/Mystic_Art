#pragma once
#include "gameNode.h"
#include "State.h"

struct tagPlayer
{
	RECT _rc;
	RECT _rcimg;
	image* _Player_img;

	float _x, _y;
	float _height;
	float _speed;
	float _jumpPower;
	float _jumpCount;
	float _grvity;
	float _probeY;

	bool _isJump;
	bool _isFall;
	bool _isLanding;
	bool _isDownJump;
	/* _dir | TRUE = RIGHT, FALSE = LEFT */
	bool _dir;
};

class Player : public gameNode
{
private:
	tagPlayer _player;

public:
	/* ���� ���� */
	void InputHandle();
	State* _state;

	/* ������ & �Ҹ���*/
	Player();
	~Player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	/* ���漱�� */
	tagPlayer* getTagPlayer() { return &_player; }		

	/* Init */
	void set_Player();

	/* Update */
	void pixelCollision();

	/* Collision */
	void On_Screen();
};