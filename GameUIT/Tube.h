﻿#pragma once
#include "GameObject.h"
#include "ShootingFlower.h"
#include "PlayScene.h"

#define TUBE_BBOX_WIDTH		34
#define TUBE_BBOX_HEIGHT	48
#define TUBE_CARNI_BBOX_HEIGHT	28

#define TUBE_HAS_RED_SHOOTING_FLOWER 1
#define TUBE_HAS_GREEN_SHOOTING_FLOWER 2
#define TUBE_HAS_GREEN_CARNIVOURING_FLOWER 3

#define ATTACK_ZONE 90.0f
#define SAFE_ZONE 45.0f
#define SAFE_ZONE_CARNI_FLOWER 25.0f

#define ID_ANI_TUBE 5500
#define ID_ANI__SMALL_TUBE 5501

class CTube :public CGameObject 
{
	int Type; //Has shootin' flower, has Carni flower
	CShootingFlower* shoot_flower = NULL; //Một cái ống thì chứa một loại hoa
public:
	CTube(float x, float y, int type) :CGameObject(x, y) 
	{ 
		CPlayScene* current_scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
		this->Type = type; 
		shoot_flower = new CShootingFlower(this->x, this->y, type);
		current_scene->AddObjectToScene(shoot_flower); 
		//add nó vào scene nhưng vì Mario chưa lại gần Red_zone nên nó sẽ ở 
		//trạng thái wait -> chờ được vẽ và cập nhật lên
	};

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects); //gọi hoa trong hàm update
	void Render();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	int IsCollidable() { return 1; }
	void SpawnShootingFlower();
};