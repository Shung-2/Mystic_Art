#pragma once
class Player;
class State
{
public:
	virtual State* inputHandle(Player* player) = 0;
	virtual void update(Player* player) = 0;
	virtual void enter(Player* player) = 0;
	virtual void exit(Player* player) = 0;
};