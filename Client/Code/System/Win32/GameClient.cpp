#include "StdAfx.h"
#include "GameClient.h"

GameClient::GameClient()
{
	gEnv->pGameClient = this;
	Init();
}

GameClient::~GameClient()
{
	gEnv->pGameClient = NULL;
}

bool GameClient::Init()
{
	m_LocalGameState = STATE_LOGIN_FRAME;
	return true;
}

void GameClient::Run(int32 nFrameTime)
{

	gEnv->pRenderer->RenderGUI(m_LocalGameState);
}

void GameClient::Shutdown()
{
}