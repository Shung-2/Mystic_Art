#pragma once
#include "State.h"

class JumpState : public State
{
	int frameCount;
	virtual State* inputHandle(Player* player);
	virtual void update(Player* player);
	virtual void enter(Player* player);
	virtual void exit(Player* player);
};