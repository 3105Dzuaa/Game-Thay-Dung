﻿#include "Mario.h"

void CMario::Render()
{
	HandleUntouchableDrawState(); //đặt đây thì hợp lý hơn
	if (isEvolving && level == MARIO_LEVEL_BIG && isEvolveForward) return; //Big biến thành gấu mèo thì 0 vẽ trong 1 khoảng thgian
	if (isEvolving && level == MARIO_LEVEL_RACOON && isEvolveBackward) return; //Gấu mèo biến về Big thì cũng 0 vẽ
	if (untouchable && untouch_0) return;

	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (state == MARIO_STATE_DIE)
		aniId = ID_ANI_MARIO_DIE;
	else if (level == MARIO_LEVEL_BIG)
		aniId = GetAniIdBig();
	else if (level == MARIO_LEVEL_SMALL)
		aniId = GetAniIdSmall();
	else if (level == MARIO_LEVEL_RACOON)
		aniId = GetAniIdRacoon();

	animations->Get(aniId)->Render(x, y, false);
	//RenderBoundingBox();
}

void CMario::HandleUntouchableDrawState()
{
	//0 vẽ
	if (untouchable && GetTickCount64() - untouch_draw_0 >= UNTOUCH_DRAW_TIME && untouch_0)
	{
		untouch_0 = 0;
		untouch_1 = 1;
		untouch_draw_0 = 0;
		untouch_draw_1 = GetTickCount64();
	} //vẽ
	else if (untouchable && GetTickCount64() - untouch_draw_1 >= UNTOUCH_DRAW_TIME && untouch_1)
	{
		untouch_0 = 1;
		untouch_1 = 0;
		untouch_draw_0 = GetTickCount64();
		untouch_draw_1 = 0;
	}
}

//
// Get animation ID for small Mario
//

int CMario::GetAniIdSmall()
{
	int aniId = -1;

	if (!isOnPlatform)
	{
		if (isEvolving && isEvolveForward)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_LEFT;
		}
		else if (isHolding)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_HOLD_JUMP_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_HOLD_JUMP_LEFT;
		}
		else if (isAtMaxSpeed)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_JUMP_AT_MAX_SPEED_RIGHT;
			else if (nx < 0)
				aniId = ID_ANI_MARIO_SMALL_JUMP_AT_MAX_SPEED_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT;
		}
	}
	else
	{
		if (isKicking)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_KICKING_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_KICKING_LEFT;
		}
		else if (isEvolving && isEvolveForward)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_LEFT;
		}
		else if (isHolding)
		{
			if (nx > 0 && vx > 0)
				aniId = ID_ANI_MARIO_SMALL_HOLD_WALK_RIGHT;
			else if (nx < 0 && vx < 0)
				aniId = ID_ANI_MARIO_SMALL_HOLD_WALK_LEFT;
			else if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_HOLD_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_HOLD_LEFT;
		}
		else
		{
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;
				else aniId = ID_ANI_MARIO_SMALL_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_SMALL_BRACE_RIGHT;
				else if (vx >= maxRunningSpeed)  //Đặt thằng này lên trc vì lúc chạy ax = accel run (obviously!)
					aniId = ID_ANI_MARIO_SMALL_RUNNING_MAX_SPEED_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_SMALL_RUNNING_RIGHT;
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_SMALL_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_SMALL_BRACE_LEFT;
				else if (abs(vx) >= maxRunningSpeed)
					aniId = ID_ANI_MARIO_SMALL_RUNNING_MAX_SPEED_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_SMALL_RUNNING_LEFT;
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_SMALL_WALKING_LEFT;
			}
		}
	}

	if (aniId == -1) aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;

	return aniId;
}

//
// Get animdation ID for big Mario
//

int CMario::GetAniIdBig()
{
	int aniId = -1;
	if (!isOnPlatform) //ĐANG BAY || LƯỢN
	{
		if (isEvolving && isEvolveForward)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_LEFT;
		}
		else if (isEvolving && isEvolveBackward)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_LEFT;
		}
		else if (isHolding)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_BIG_HOLDING_JUMPING_RIGHT;
			else
				aniId = ID_ANI_MARIO_BIG_HOLDING_JUMPING_LEFT;
		}
		else if (isAtMaxSpeed)
		{
			if (nx > 0)  //prob here
				aniId = ID_ANI_MARIO_BIG_JUMP_AT_MAX_SPEED_RIGHT;
			else if (nx < 0)
				aniId = ID_ANI_MARIO_BIG_JUMP_AT_MAX_SPEED_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_MARIO_JUMP_WALK_LEFT;
		}
	}
	else
	{
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SIT_RIGHT;
			else
				aniId = ID_ANI_MARIO_SIT_LEFT;
		}
		else if (isKicking)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_KICKING_RIGHT;
			else
				aniId = ID_ANI_MARIO_KICKING_LEFT;
		}
		else if (isEvolving && isEvolveBackward) //tiến hoá lùi
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_EVOLVE_TO_BIG_LEFT;
		}
		else if (isHolding)
		{
			if (nx > 0 && vx > 0)
				aniId = ID_ANI_MARIO_BIG_HOLDING_WAKING_RIGHT;
			else if (nx < 0 && vx < 0)
				aniId = ID_ANI_MARIO_BIG_HOLDING_WAKING_LEFT;
			else if (nx > 0)
				aniId = ID_ANI_MARIO_BIG_HOLDING_RIGHT;
			else
				aniId = ID_ANI_MARIO_BIG_HOLDING_LEFT;
		}
		else
		{
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_MARIO_IDLE_RIGHT;
				else aniId = ID_ANI_MARIO_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_BRACE_RIGHT;
				else if (isAtMaxSpeed)  //prob here
					aniId = ID_ANI_MARIO_BIG_RUNNING_MAX_SPEED_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_RUNNING_RIGHT;
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_BRACE_LEFT;
				else if (isAtMaxSpeed)
					aniId = ID_ANI_MARIO_BIG_RUNNING_MAX_SPEED_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_RUNNING_LEFT;
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_WALKING_LEFT;
			}
		}
	}
	if (aniId == -1) aniId = ID_ANI_MARIO_IDLE_RIGHT;

	return aniId;
}

//
//Id for Racoon Mario
//

int CMario::GetAniIdRacoon()
{
	int aniId = -1;
	if (!isOnPlatform) //included fly, jump, landing, fall
	{
		if (nx > 0 && isFlying)
		{
			aniId = ID_ANI_MARIO_RACOON_FLYING_RIGHT; 
		}
		else if (nx < 0 && isFlying)
		{
			aniId = ID_ANI_MARIO_RACOON_FLYING_LEFT;
		}
		else if (nx < 0 && isLanding) 
		{
			aniId = ID_ANI_MARIO_RACOON_LANDING_LEFT; 
		}
		else if (nx > 0 && isLanding)
		{
			aniId = ID_ANI_MARIO_RACOON_LANDING_RIGHT;
		}
		else if (isAttacking && nx > 0)
		{
			aniId = ID_ANI_MARIO_RACOON_ATTACKING_RIGHT;
		}
		else if (isAttacking && nx < 0)
		{
			aniId = ID_ANI_MARIO_RACOON_ATTACKING_LEFT;
		}
		else if (isHolding)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_RACOON_HOLD_JUMP_RIGHT;
			else
				aniId = ID_ANI_MARIO_RACOON_HOLD_JUMP_LEFT;
		}
		else if (nx > 0 && vy > 0) //Falling
		{
			aniId = ID_ANI_MARIO_RACOON_FALLING_RIGHT; //có vào đây
		}
		else if (nx < 0 && vy > 0)
		{
			aniId = ID_ANI_MARIO_RACOON_FALLING_LEFT;
		}
		else
		{
			if (isAtMaxSpeed)
			{
				if (nx > 0) 
					aniId = ID_ANI_MARIO_RACOON_JUMP_AT_MAX_SPEED_RIGHT;
				else if (nx < 0)
					aniId = ID_ANI_MARIO_RACOON_JUMP_AT_MAX_SPEED_LEFT;
			}
			else
			{
				if (nx >= 0)
					aniId = ID_ANI_MARIO_RACOON_JUMP_WALK_RIGHT;
				else
					aniId = ID_ANI_MARIO_RACOON_JUMP_WALK_LEFT;
			}
		}
	}
	else
	{
		if (isUsingTube)
		{
			aniId = ID_ANI_MARIO_RACOON_USING_TUBE;
		}
		else if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_RACOON_SIT_RIGHT;
			else
				aniId = ID_ANI_MARIO_RACOON_SIT_LEFT;
		}
		else if (isKicking)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_RACOON_KICKING_RIGHT;
			else
				aniId = ID_ANI_MARIO_RACOON_KICKING_LEFT;
		}
		else if (isAttacking)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_RACOON_ATTACKING_RIGHT;
			else
				aniId = ID_ANI_MARIO_RACOON_ATTACKING_LEFT;
		}
		else if (isHolding)
		{
			if (nx > 0 && vx > 0)
				aniId = ID_ANI_MARIO_RACOON_HOLD_WALK_RIGHT;
			else if (nx < 0 && vx < 0)
				aniId = ID_ANI_MARIO_RACOON_HOLD_WALK_LEFT;
			else if (nx > 0)
				aniId = ID_ANI_MARIO_RACOON_HOLD_RIGHT;
			else
				aniId = ID_ANI_MARIO_RACOON_HOLD_LEFT;
		}
		else
		{
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_MARIO_RACOON_IDLE_RIGHT;
				else aniId = ID_ANI_MARIO_RACOON_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_RACOON_BRACE_LEFT;
				else if (vx >= maxRunningSpeed)
					aniId = ID_ANI_MARIO_RACOON_RUNNING_MAX_SPEED_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_RACOON_RUNNING_RIGHT;
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_RACOON_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_RACOON_BRACE_RIGHT;
				else if (abs(vx) >= maxRunningSpeed)
					aniId = ID_ANI_MARIO_RACOON_RUNNING_MAX_SPEED_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_RACOON_RUNNING_LEFT;
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_RACOON_WALKING_LEFT;
			}
		}
	}

	if (aniId == -1) aniId = ID_ANI_MARIO_RACOON_IDLE_RIGHT;

	return aniId;
}