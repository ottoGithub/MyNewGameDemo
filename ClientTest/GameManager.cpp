#include "StdAfx.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "ActorManager.h"
#include "Camera.h"

void GameManager::EnterGameState(int nStateID)
{
	gGameStateID = nStateID;
	if(gGameStateID == eGameState_LoadScene)
	{
		SceneManager::Instance().LoadScene(0);
		ActorManager::Instance().CreateActor(0x0001, ObjType_MyPlayer);
		SceneManager::Instance().EnterScene((Actor*)ActorManager::Instance().GetMyPlayer());
		
		for(int x = 0, i = 0; x < gCharacterTexture.getWidth(); x += CHARACTER_W, ++i)
			for(int y = 0, j = 0; y < gCharacterTexture.getHeight(); y += CHARACTER_H, ++j)
			{
				gRectCharterAnim[j][i].x = x;
				gRectCharterAnim[j][i].y = y;
				gRectCharterAnim[j][i].w = CHARACTER_W;
				gRectCharterAnim[j][i].h = CHARACTER_H;
			}
	}
}

void GameManager::Tick(int nFrameTime)
{
	SceneManager::Instance().Tick(nFrameTime);
	ActorManager::Instance().Tick(nFrameTime);

	Camera::Instance().Tick(nFrameTime);
}