#include "StdAfx.h"
#include "GameApp.h"
#include <SDL.h>
#include "System/Win32/SystemWin32.h"
#include "System/Win32/GameClient.h"

namespace XT_CLIENT
{
	GameApp::GameApp()
	{
		gWinData.m_pProcessInfo = NULL;
		gWinData.m_pSDLWindow = NULL;
		m_pSystem = NULL;
	}

	GameApp::~GameApp()
	{
		Shutdown();
	}

	void GameApp::Run()
	{
		if(!Init())
		{
			return;
		}
		//Main loop flag
		bool quit = false;
		//Event handler
		SDL_Event e;
		Uint32 nStartTime = 0;
		Uint32 nFrameTime = 0;
		//While application is running
		while( !quit )
		{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
				//ImGui_ImplSdl_ProcessEvent(&event);
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
				else
				{
					//KeyEventListenerManager::Instance().HandlerEvent(e);
				}
			}
			nStartTime = SDL_GetTicks();

			m_pSystem->Process(nFrameTime);

			nFrameTime = SDL_GetTicks() - nStartTime;
		}

		Shutdown();
	}
	bool GameApp::Init()
	{
		m_pSystem = new SystemWin32();
		gEnv = m_pSystem->GetGlobalEnvironment();
		if(!m_pSystem->Init())
		{
			SAFE_DELETE(m_pSystem);
			return false;
		}

		return true;
	}

	void GameApp::Shutdown()
	{
		SAFE_DELETE(m_pSystem);
	}

	void GameApp::SetProcessInfo( ProcessInfoWin32* pProcessInfo )
	{
		gWinData.m_pProcessInfo = pProcessInfo;
	}

}
