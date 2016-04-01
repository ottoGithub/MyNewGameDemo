#include "StdAfx.h"
#include "GameApp.h"
#include "System/Win32/SystemWin32.h"
#include "System/Win32/Win32GameFrameWork.h"
#include "System/Win32/GameClient.h"

namespace XT_CLIENT
{
	GameApp::GameApp()
	{
		m_pProcessInfo = NULL;
		m_pGameFrameWork = NULL;
		m_pSystem = NULL;
		m_pGameClient = NULL;
	}

	GameApp::~GameApp()
	{
		Shutdown();
	}

	void GameApp::Run()
	{
		if(Init())
		{
			m_pSystem->Process();
		}
		Shutdown();
	}

	bool GameApp::Init()
	{
		m_pSystem = new SystemWin32();
		if(!m_pSystem->Init(m_pProcessInfo))
		{
			SAFE_DELETE(m_pSystem);
			return false;
		}
		gEnv = m_pSystem->GetGlobalEnvironment();

		//InitFrameWork
		m_pGameFrameWork = new GameFrameWorkWin32();
		if(!m_pGameFrameWork->Init(m_pSystem))
		{
			SAFE_DELETE(m_pGameFrameWork);
			return false;
		}

		//InitGameClient
		m_pGameClient = new GameClient();
		if(!m_pGameClient->Init())
		{
			SAFE_DELETE(m_pGameClient);
			return false;
		}
		return true;
	}

	void GameApp::Shutdown()
	{
		SAFE_DELETE(m_pSystem);
		SAFE_DELETE(m_pGameFrameWork);
		SAFE_DELETE(m_pGameClient);
	}

	void GameApp::SetProcessInfo( ProcessInfoWin32* pProcessInfo )
	{
		m_pProcessInfo = pProcessInfo;
	}

}
