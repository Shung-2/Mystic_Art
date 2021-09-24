#include "stdafx.h"
#include "Player.h"
#include "IdelState.h"
#include "RunState.h"
#include "JumpState.h"
#include "Jump_FallState.h"

State* RunState::inputHandle(Player* player)
{
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		return new IdelState();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		return new IdelState();
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		return new JumpState();
	}
	if (!player->getTagPlayer()->_isLanding)
	{
		return new Jump_FallState();
	}
	return nullptr;
}

void RunState::update(Player* player)
{
	/* �������¿��� �ٴ� ���·� ���ص� ���������ϱ� ������ �־�� �� */
	if (player->getTagPlayer()->_jumpPower < 0)
	{
		player->getTagPlayer()->_isLanding = false;
	}

	player->getTagPlayer()->_y -= player->getTagPlayer()->_jumpPower;
	player->getTagPlayer()->_jumpPower -= player->getTagPlayer()->_grvity;

	frameCount++;

	/* _dir | TRUE = RIGHT, FALSE = LEFT */
	if (player->getTagPlayer()->_dir)
	{		
		player->getTagPlayer()->_x += player->getTagPlayer()->_speed;

		if (frameCount >= 5.5)
		{
			frameCount = 0;
			
			if (player->getTagPlayer()->_Player_img->getFrameX() >=player->getTagPlayer()->_Player_img->getMaxFrameX())
				player->getTagPlayer()->_Player_img->setFrameX(0);

			player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getFrameX() + 1);
			player->getTagPlayer()->_Player_img->setFrameY(0);
		}
	}
	else
	{
		player->getTagPlayer()->_x -= player->getTagPlayer()->_speed;

		if (frameCount >= 5.5)
		{
			frameCount = 0;

			if (player->getTagPlayer()->_Player_img->getFrameX() == 0)
				player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getMaxFrameX());

			player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getFrameX() - 1);
			player->getTagPlayer()->_Player_img->setFrameY(1);
		}
	}
}

void RunState::enter(Player* player)
{

	player->getTagPlayer()->_jumpCount++;

	/* �̹��� �ε� */
	player->getTagPlayer()->_Player_img = IMAGEMANAGER->findImage("PLAYER RUN");

	/* �̹��� ������ ���� �ʱ�ȭ */
	/* TRUE = RIGHT, FALSE = LEFT */
	if (player->getTagPlayer()->_dir)
	{
		player->getTagPlayer()->_Player_img->setFrameX(0);
		player->getTagPlayer()->_Player_img->setFrameY(0);
	}
	else
	{
		player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getMaxFrameX());
		player->getTagPlayer()->_Player_img->setFrameY(1);
	}

	return;
}

void RunState::exit(Player* player)
{

}
