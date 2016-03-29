#include "StdAfx.h"
#include "Actor.h"
#include "PhysicsFunctions.h"

Actor::Actor() : m_vPos(0,0),m_vDir(0,0)
{
	m_nVelocity = 0;
	m_nGuid = 0;
	m_nSceneID = 0;
}

Actor::~Actor()
{

}

void Actor::Tick(int nFrameTime)
{
	float fFrameTime = nFrameTime / 1000.0f;
	if(!m_vDir.IsZero(MIN_FLOAT))
	{
		DoMove(fFrameTime);
	}

}

void Actor::DoMove(float fMoveTime)
{
	Vector2D vNewPos = m_vPos + m_nVelocity * fMoveTime * m_vDir;
	
	DoBoundaryCheck(vNewPos);
	DoCheckCollision(vNewPos);

	m_vPos = vNewPos;
}

void Actor::DoCheckCollision(Vector2D& vPos)
{

}
void Actor::DoBoundaryCheck(Vector2D& vPos)
{
	//boundary check;
	if(int(vPos.x) - CHARACTER_W/2 < 0 )
	{
		vPos.x = CHARACTER_W/2;
	}
	if(int(vPos.x) + CHARACTER_W/2 > LEVEL_WIDTH)
	{
		vPos.x = LEVEL_WIDTH - CHARACTER_W/2;
	}
	if(int(vPos.y) - CHARACTER_H < 0 )
	{
		vPos.y = CHARACTER_H;
	}
	if(int(vPos.y)  > LEVEL_HEIGHT)
	{
		vPos.y = LEVEL_HEIGHT;
	}

}

void Actor::RenderActor(SDL_Rect& rectView)
{
	static int nFrameCount = 0;
	nFrameCount %= WALKING_ANIMATION_FRAMES * ANIM_PLAY_FRAME_COUNT;
	static int nDirAnimIndex = e_Down_Anim;
	if(m_vDir.IsEqual(Vector2D(0, -1),MIN_FLOAT))
	{
		nDirAnimIndex = e_Up_Anim;
	}
	else if(m_vDir.IsEqual(Vector2D(0, 1),MIN_FLOAT))
	{
		nDirAnimIndex = e_Down_Anim;
	}
	else if (m_vDir.IsEqual(Vector2D(-1, 0),MIN_FLOAT))
	{
		nDirAnimIndex = e_Left_Anim;
	}
	else if (m_vDir.IsEqual(Vector2D(1, 0),MIN_FLOAT))
	{
		nDirAnimIndex = e_Right_Anim;
	}
	else
	{
		nFrameCount = 0;
	}
	Vector2D vRealPos = GetActorRealPos(m_vPos);

	gCharacterTexture.render(int(vRealPos.x - rectView.x), int(vRealPos.y - rectView.y), &gRectCharterAnim[nDirAnimIndex][nFrameCount / ANIM_PLAY_FRAME_COUNT]);
	++nFrameCount;
}