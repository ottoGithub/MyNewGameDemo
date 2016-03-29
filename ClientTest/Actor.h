#ifndef _ACTOR_H_
#define _ACTOR_H_
#include "CommonDef.h"
class Actor
{
public:
	Actor();
	virtual ~Actor();
	virtual void Tick(int nFrameTime);
public:
	void SetDir(Vector2D& vDir) { m_vDir = vDir; }
	
	void SetPos(Vector2D& vPos) { m_vPos.x = vPos.x; m_vPos.y = vPos.y; }
	Vector2D GetPos() { return m_vPos; }

	void SetSpeed(int v) { m_nVelocity = v;}

	void SetGuid(int id) { m_nGuid = id; }
	int GetGuid() { return m_nGuid; }

	void SetScene(int nSceneID) { m_nSceneID = nSceneID; }


	void RenderActor(SDL_Rect& rectView);
protected:
	//暂时不用状态机
	void DoMove(float fMoveTime);
	void DoCheckCollision(Vector2D& vPos);
	void DoBoundaryCheck(Vector2D& vPos);

protected:
	int m_nGuid;

	Vector2D m_vDir;
	Vector2D m_vPos;
	int m_nVelocity;

	int m_nSceneID;
};

#endif