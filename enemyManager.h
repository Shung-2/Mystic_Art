#pragma once
#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>

//상호참조를 위한 클라스 전방선언
class spaceShip;

class enemyManager : public gameNode
{
private:
	// 왜 minion이 아닌 enemy를 사용할까?
	// enemy안에 minion이 아니라도 다른 것들도 넣기 위해서
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;
	bullet* _bullet;

	//얘는 빈 포인터에 불과하다 아직은
	spaceShip* _ship;

public:
	enemyManager() {};
	~enemyManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setMinion();
	//void minionBulletFire();
	void removeMinion(int arrNum);
	//void collision();

	//단지 설정자인데 함수이름이 그럴싸함 주의
	void setSpaceShipMemoryAddressLink(spaceShip* ship) { _ship = ship; }

	vector<enemy*> getVMinion() { return _vMinion; }
	vector<enemy*>::iterator getVIMinion() { return _viMinion; }
};