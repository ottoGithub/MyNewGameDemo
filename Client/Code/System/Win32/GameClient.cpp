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
	m_LocalGameState = STATE_START;
	return true;
}

void GameClient::Run()
{

}

void GameClient::Shutdown()
{
}