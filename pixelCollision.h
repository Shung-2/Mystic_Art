#pragma once
#include "gameNode.h"
#include "Player.h"

class Player;

class pixelCollision : public gameNode
{
private:

	Player* _Player;

public:
	pixelCollision();
	~pixelCollision();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayerAddressLink(Player* pl)
	{
		_Player = pl;
	}
};

