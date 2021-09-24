#pragma once
#include "gameNode.h"
#include "Player.h"

class Player;

class Stage3 : public gameNode
{
private:
	Player* _Player;

	RECT _Stage3_Obj[3];
	RECT _Stage3_Rand;

public:
	Stage3();
	~Stage3();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayerAddressLink(Player* pl) { _Player = pl; }
};

