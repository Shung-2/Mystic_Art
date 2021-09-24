#include "stdafx.h"
#include "Player.h"
#include "IdelState.h"
#include "RunState.h"
#include "JumpState.h"
#include "Jump_FallState.h"

State* Jump_FallState::inputHandle(Player* player)
{
	//if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	//{
	//	return new IdelState();
	//}
	//if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	//{
	//	return new IdelState();
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	//{
	//	return new RunState();
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	//{
	//	return new RunState();
	//}

	if (player->getTagPlayer()->_isLanding)
	{
		return new IdelState();
	}
	return nullptr;
}

void Jump_FallState::update(Player* player)
{
	/* JUMP(하락) STAGE */
	player->getTagPlayer()->_y -= player->getTagPlayer()->_jumpPower;
	player->getTagPlayer()->_jumpPower -= player->getTagPlayer()->_grvity;

	/* 점프 중 이동상태 */
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		player->getTagPlayer()->_dir = true;
		player->getTagPlayer()->_x += player->getTagPlayer()->_speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		player->getTagPlayer()->_dir = false;
		player->getTagPlayer()->_x -= player->getTagPlayer()->_speed;
	}

	/* 점프 프레임 부분 */
	frameCount++;

	/* _dir | TRUE = RIGHT, FALSE = LEFT */
	if (player->getTagPlayer()->_dir)
	{
		if (frameCount >= 4)
		{
			frameCount = 0;

			if (player->getTagPlayer()->_Player_img->getFrameX() >= player->getTagPlayer()->_Player_img->getMaxFrameX())
				player->getTagPlayer()->_Player_img->setFrameX(2);

			player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getFrameX() + 1);
			player->getTagPlayer()->_Player_img->setFrameY(0);
		}
	}
	else
	{
		if (frameCount >= 4)
		{
			frameCount = 0;

			if (player->getTagPlayer()->_Player_img->getFrameX() == player->getTagPlayer()->_Player_img->getMaxFrameX() - 4)
				player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getMaxFrameX() - 2);

			player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getFrameX() - 1);
			player->getTagPlayer()->_Player_img->setFrameY(1);
		}
	}	
}

void Jump_FallState::enter(Player* player)
{
	/* 이미지 로드 */
	player->getTagPlayer()->_Player_img = IMAGEMANAGER->findImage("PLAYER JUMP");

	/* 이미지 프레임 방향 초기화 */
	/* TRUE = RIGHT, FALSE = LEFT */
	if (player->getTagPlayer()->_dir)
	{
		player->getTagPlayer()->_Player_img->setFrameX(2);
		player->getTagPlayer()->_Player_img->setFrameY(0);
	}
	else
	{
		player->getTagPlayer()->_Player_img->setFrameX(2);
		player->getTagPlayer()->_Player_img->setFrameY(1);
	}

	return;
}

void Jump_FallState::exit(Player* player)
{
}
