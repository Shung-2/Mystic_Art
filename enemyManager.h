#pragma once
#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>

//��ȣ������ ���� Ŭ�� ���漱��
class spaceShip;

class enemyManager : public gameNode
{
private:
	// �� minion�� �ƴ� enemy�� ����ұ�?
	// enemy�ȿ� minion�� �ƴ϶� �ٸ� �͵鵵 �ֱ� ���ؼ�
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;
	bullet* _bullet;

	//��� �� �����Ϳ� �Ұ��ϴ� ������
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

	//���� �������ε� �Լ��̸��� �׷����� ����
	void setSpaceShipMemoryAddressLink(spaceShip* ship) { _ship = ship; }

	vector<enemy*> getVMinion() { return _vMinion; }
	vector<enemy*>::iterator getVIMinion() { return _viMinion; }
};