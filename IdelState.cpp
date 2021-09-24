#include "stdafx.h"
#include "Player.h"
#include "IdelState.h"
#include "RunState.h"
#include "JumpState.h"
#include "Jump_FallState.h"

State* IdelState::inputHandle(Player* player)
{
	/* _dir | TRUE = RIGHT, FALSE = LEFT */
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) || KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		player->getTagPlayer()->_dir = true;
		return new RunState();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		player->getTagPlayer()->_dir = false;
		return new RunState();
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			player->getTagPlayer()->_isDownJump = true;
			player->getTagPlayer()->_isLanding = false;
			return new Jump_FallState();
		}
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		return new JumpState();
	}

	return nullptr;
}

void IdelState::update(Player* player)
{	
	player->getTagPlayer()->_y -= player->getTagPlayer()->_jumpPower;
	player->getTagPlayer()->_jumpPower -= player->getTagPlayer()->_grvity;

	frameCount++;

	/* _dir | TRUE = RIGHT, FALSE = LEFT */
	if (player->getTagPlayer()->_dir)
	{
		if (frameCount >= 10)
		{
			frameCount = 0;
			if (player->getTagPlayer()->_Player_img->getFrameX() >=
				player->getTagPlayer()->_Player_img->getMaxFrameX())
			{
				player->getTagPlayer()->_Player_img->setFrameX(0);
			}
			player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getFrameX() + 1);
			player->getTagPlayer()->_Player_img->setFrameY(0);
		}
	}
	else
	{
		if (frameCount >= 10)
		{
			frameCount = 0;
			if (player->getTagPlayer()->_Player_img->getFrameX() == 0)
			{
				player->getTagPlayer()->_Player_img->setFrameX(
					player->getTagPlayer()->_Player_img->getMaxFrameX()
				);
			}
			player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getFrameX() - 1);
			player->getTagPlayer()->_Player_img->setFrameY(1);
		}
	}
}

void IdelState::enter(Player* player)
{	
	/* 이미지 로드 */
	player->getTagPlayer()->_Player_img = IMAGEMANAGER->findImage("PLAYER IDEL");	

	/* 이미지 프레임 방향 초기화 */
	/* _dir | TRUE = RIGHT, FALSE = LEFT */
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

void IdelState::exit(Player* player)
{
}