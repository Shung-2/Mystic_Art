#pragma once
#include "gameNode.h"

class testScene2 : public gameNode
{
private:
	RECT _Intro_MysticArtsLogo;
	RECT _Intro_CoinCharacterLogo;

public:
	testScene2();
	~testScene2();

	HRESULT init();
	void release();
	void update();
	void render();
};

