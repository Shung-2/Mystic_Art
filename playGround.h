#pragma once
#include "gameNode.h"
//#include "spaceShip.h"
#include "testScene.h"
#include "testScene2.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Player.h"

class playGround : public gameNode
{
private:
	//spaceShip* _ship;
	Player* pl;
	Stage1* st;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();	
};