#include "StdAfx.h"
#include "GameApp.h"
#include "System/Win32/SystemWin32.h"

namespace XT_CLIENT
{
	GameApp::GameApp()
	{

	}

	GameApp::~GameApp()
	{

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
			return false;
		}
		return true;
	}

	void GameApp::Shutdown()
	{
	}

	void GameApp::SetProcessInfo( ProcessInfoWin32* pProcessInfo )
	{
		m_pProcessInfo = pProcessInfo;
	}

}
