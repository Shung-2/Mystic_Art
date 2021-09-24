#pragma once
#include "State.h"

class Player;

class IdelState : public State
{
public:
	int frameCount;
	virtual State* inputHandle(Player* player);
	virtual void update(Player* player);
	virtual void enter(Player* player);
	virtual void exit(Player* player);
};