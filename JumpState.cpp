#include "stdafx.h"
#include "Player.h"
#include "IdelState.h"
#include "RunState.h"
#include "JumpState.h"
#include "Jump_FallState.h"

State* JumpState::inputHandle(Player* player)
{
	if (player->getTagPlayer()->_jumpPower < 0)
	{
		return new Jump_FallState();
	}

	return nullptr;
}

void JumpState::update(Player* player)
{
	/* JUMP(상승) STAGE*/
	if (player->getTagPlayer()->_isJump)
	{
		player->getTagPlayer()->_y -= player->getTagPlayer()->_jumpPower;
		player->getTagPlayer()->_jumpPower -= player->getTagPlayer()->_grvity;
	}	

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
		if (frameCount >= 5)
		{
			frameCount = 0;

			//if (player->getTagPlayer()->_Player_img->getFrameX() == player->getTagPlayer()->_Player_img->getMaxFrameX() - 2)
			//	player->getTagPlayer()->_Player_img->setFrameX(0);

			player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getFrameX() + 1);
			player->getTagPlayer()->_Player_img->setFrameY(0);
		}
	}
	else
	{
		if (frameCount >= 5)
		{
			frameCount = 0;

			if (player->getTagPlayer()->_Player_img->getFrameX() == player->getTagPlayer()->_Player_img->getMaxFrameX() - 3)
				player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getMaxFrameX() - 2);

			player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getFrameX() - 1);
			player->getTagPlayer()->_Player_img->setFrameY(1);
		}
	}
}

void JumpState::enter(Player* player)
{
	player->getTagPlayer()->_isJump = true;
	player->getTagPlayer()->_isLanding = false;

	player->getTagPlayer()->_jumpCount++;
	player->getTagPlayer()->_jumpPower = 18.0f;
	player->getTagPlayer()->_grvity = 0.5f;

	/* 이미지 로드 */
	player->getTagPlayer()->_Player_img = IMAGEMANAGER->findImage("PLAYER JUMP");

	/* 이미지 프레임 방향 초기화 */
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

void JumpState::exit(Player* player)
{
}
