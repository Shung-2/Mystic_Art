#pragma once
#include "gameNode.h"

enum TITLEMENU
{
	GAME_START,
	OPTION,
	EXIT
};

class testScene : public gameNode
{
private:
	RECT _Intro_MysticArtsLogo;
	RECT _Intro_CoinCharacterLogo;
	RECT _Intro_TTLMenuAll;
	RECT _Intro_TitleMenu[3];
	
	bool _IntroBG_Black_To_BeforeKeyPressBG;
	bool _IntroBG_BeforeKeyPressBG_To_AfterKeyPressBG;
	bool _Print_TitleMenu;

	TITLEMENU _Choice;
	image* _Choice_img;
	int _TitleMenu_Index;

public:
	testScene();
	~testScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

