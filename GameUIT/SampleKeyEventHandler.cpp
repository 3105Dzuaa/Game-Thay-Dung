﻿#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "Koopa.h"
#include "PlayScene.h"

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CGame* game = CGame::GetInstance();
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_RIGHT:
		if (!mario->GetIsTravelling())
			mario->SetState(MARIO_STATE_WALKING_RIGHT);
		break;

	case DIK_LEFT:
		if (!mario->GetIsTravelling())
			mario->SetState(MARIO_STATE_WALKING_LEFT);
		break;

	case DIK_DOWN:
		if (!mario->GetIsAllowToUseTube())
			mario->SetState(MARIO_STATE_SIT);
		else
		{
			mario->SetIsTravelDown(true);
			mario->SetState(MARIO_STATE_TRAVELLING);
		}
		break;

	case DIK_Z: //Tạm cài nút Z vì nút A có lỗi ch fix đc
		if (mario->GetIsAttacking()) break;
		if (mario->GetLevel() == MARIO_LEVEL_RACOON)
			mario->SetState(MARIO_RACOON_STATE_ATTACK);
		break;

	case DIK_S: //nếu là racoon mario thì bơm thêm vận tốc theo trục y để bay
		 if (mario->GetCanFly() && mario->GetLevel() == MARIO_LEVEL_RACOON)
			mario->SetState(MARIO_RACOON_STATE_FLYING); //Max speed + Racoon -> bay
		 else  if (!mario->GetIsOnPlatform() && mario->GetLevel() == MARIO_LEVEL_RACOON && !mario->GetIsFlying())
		 {
			 //Nếu Racoon 0 ở trên nền mà còn bấm S
			 //VÀ không phải trạng thái BAY thì bật state hạ cánh
			 mario->SetState(MARIO_RACOON_STATE_LANDING);
		 }
		 else if (mario->GetisAtMaxSpeed() && !mario->GetIsFlying())
		 {
			 if (mario->GetMarioNormalX() > 0)
				 mario->SetState(MARIO_STATE_RUNNING_AT_MAX_SPEED_RIGHT);
			 else if (mario->GetMarioNormalX() < 0)
				 mario->SetState(MARIO_STATE_RUNNING_AT_MAX_SPEED_LEFT);
		 }
		else if (mario->GetIsAttacking())
			mario->SetState(MARIO_RACOON_STATE_ATTACK);
		else if (mario->GetIsOnPlatform()) //Phải ở trên nền thì mới cho nhảy 
			mario->SetState(MARIO_STATE_JUMPING);
		else if (game->IsKeyDown(DIK_UP))
		{
			 mario->SetIsTravelUp(true);
			 //mario->SetState(MARIO_STATE_TRAVELLING);
		}
		break;
		//case DIK_Z:
			//if (mario->GetState() == MARIO_RACOON_STATE_ATTACK) break;
			//if (mario->GetLevel() == MARIO_LEVEL_RACOON)
			//	mario->SetState(MARIO_RACOON_STATE_ATTACK);

	case DIK_T:
		mario->SetIsAtMainWorld(false);
		mario->SetPosition(130, 495);
		break;

	case DIK_B:
		mario->SetIsAtMainWorld(true);
		mario->SetPosition(2248, 60);
		break;

	case DIK_1:
		mario->SetLevel(MARIO_LEVEL_SMALL);
		break;

	case DIK_2:
		mario->SetLevel(MARIO_LEVEL_BIG);
		break;

	case DIK_3:
		mario->SetLevel(MARIO_LEVEL_RACOON);
		break;
		//set racoon attack by A here
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		mario->SetState(MARIO_STATE_RELEASE_JUMP);

		break;

	case DIK_A:
		mario->SetIsRunning(false);
		mario->SetisAtMaxSpeed(false);
		mario->SetHoldKoopa(false);
		if (mario->GetIsHolding())
			mario->SetIsHoldingKoopa(false);//gọi hàm release koopa từ mario
		break;

	case DIK_DOWN:
		if (!mario->GetIsTravelling())
			mario->SetState(MARIO_STATE_SIT_RELEASE);
		break;
	}
}

void CSampleKeyHandler::KeyState(BYTE* states)
{
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	CGame* game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		if (game->IsKeyDown(DIK_A))
		{
			if (mario->GetIsOnPlatform())
				mario->SetState(MARIO_STATE_RUNNING_RIGHT);
			mario->SetHoldKoopa(true); //giữ A thì cho phép hold Koopa
		}
		else
		{
			mario->SetState(MARIO_STATE_WALKING_RIGHT);
		}
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		if (game->IsKeyDown(DIK_A))
		{
			if (mario->GetIsOnPlatform())
				mario->SetState(MARIO_STATE_RUNNING_LEFT);
			mario->SetHoldKoopa(true); //giữ A thì cho phép hold Koopa
		}
		else
		{
			mario->SetState(MARIO_STATE_WALKING_LEFT);
		}
	}
	//else if (game->IsKeyDown(DIK_DOWN))
		//mario->SetState(MARIO_STATE_SIT);
	//else if (game->IsKeyDown(DIK_Z) && mario->GetLevel() == MARIO_LEVEL_RACOON)
		//mario->SetState(MARIO_RACOON_STATE_ATTACK);
	else
		mario->SetState(MARIO_STATE_IDLE);
}