#include "StdAfx.h"
#include "GameApp.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System/Win32/SystemWin32.h"
#include "System/Win32/Win32GameFrameWork.h"
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

			m_pSystem->Process();

			nFrameTime = SDL_GetTicks() - nStartTime;
		}

		Shutdown();
	}

	bool GameApp::InitSDL()
	{
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		{
			printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
			return false;
		}
		int imgFlags = IMG_INIT_PNG;
		if( !( IMG_Init( imgFlags ) & imgFlags ) )
		{
			printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
			return false;
		}
		return true;
	}

	void GameApp::Sys_CreateWindow()
	{
		assert(InitSDL());
		
		gWinData.m_pSDLWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	}

	bool GameApp::Init()
	{
		Sys_CreateWindow();

		m_pSystem = new SystemWin32();
		if(!m_pSystem->Init())
		{
			SAFE_DELETE(m_pSystem);
			return false;
		}
		gEnv = m_pSystem->GetGlobalEnvironment();

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
