#pragma once
#include "gameNode.h"
#include "Player.h"

class Player;

class Stage2 : public gameNode
{
private:
	Player* _Player;

	RECT _Stage2_Obj[5];
	RECT _Stage2_Rand;

public:
	Stage2();
	~Stage2();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayerAddressLink(Player* pl) { _Player = pl; }
};