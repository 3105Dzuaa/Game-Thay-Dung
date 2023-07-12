﻿#pragma once
#include "GameObject.h"
#include "ColorPlatform.h"
#include "Mario.h"

#define MARIO_NPC_WALKING_SPEED	0.15f
#define MARIO_NPC_JUMP_SPEED	0.5f

#define MARIO_NPC_STATE_LOOKUP	30
#define MARIO_NPC_STATE_NEWTON_LAW	40	//mai rơi trúng đầu

class CMarioNPC : public CGameObject
{
	float ax, ay;
	int level;
	int isOnPlatform;
	BOOLEAN isKicking, isHolding, isEvolving, isEvolveForward, isEvolveBackward;
	BOOLEAN isJumping, isLanding, isRunning, isSitting;
	float maxVx;
	ULONGLONG kick_start, evolve_start;
public:
	CMarioNPC(float x, float y) :CGameObject(x, y)
	{
		this->nx = -1;
		//ax = MARIO_ACCEL_WALK_X;
		vx = -0.01f;
		ay = 0.002f;
		level = MARIO_LEVEL_BIG;
		SetState(MARIO_STATE_WALKING_LEFT);
		isOnPlatform = 0;
		isKicking = 0;
		isHolding = 0;
		isEvolving = 0;
		isEvolveForward = 0;
		isEvolveBackward = 0;
		maxVx = 0.0f;
		kick_start = 0;
		evolve_start = 0;
		isJumping = 0;
		isLanding = 0;
		isRunning = 0;
		isSitting = 0;
	};
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	int IsBlocking() { return 0; }
	int IsCollidable() { return 1; }
	void Render();
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnCollisionWithBlockingObject(LPCOLLISIONEVENT e);
	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);

	//Quên mất thằng này, 0 có nó thì 0 colli đc @@@@@@@@@
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void SetState(int state);

	int GetAniIdBig();
	//int GetAniIdSmall();
	//int GetAniIdRacoon();
};
