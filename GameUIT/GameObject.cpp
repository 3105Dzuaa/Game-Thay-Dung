#include <d3dx9.h>
#include <algorithm>


#include "debug.h"
#include "Textures.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprites.h"
#include "Camera.h"

CGameObject::CGameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;
	state = -1;
	isDeleted = false;
	IsWaitable = 0;
	IsWaiting = 0;
}

void CGameObject::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;

	LPTEXTURE bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);

	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy); //turn out the problem of BBox was here @@

	cx = CCamera::GetInstance()->GetCamPos().x;
	cy = CCamera::GetInstance()->GetCamPos().y;

	CGame::GetInstance()->Draw(x - cx, y - cy, bbox, rect.left, rect.top, rect.right, rect.bottom, 0.25f);
}

CGameObject::~CGameObject()
{
	//should clean up
}