#include "StdAfx.h"
#include "WindowSystem.h"
#include "ProcessInfoWin32.h"
#include <SDL.h>
#include <SDL_image.h>

WindowSystem::WindowSystem()
{
	m_pProcessInfo = NULL;
	m_pSystems = NULL;
	m_pSDLWindow = NULL;
}
WindowSystem::~WindowSystem()
{

}

void WindowSystem::SetProcessInfo(ProcessInfoWin32* pProcessInfo)
{
	m_pProcessInfo = pProcessInfo;
}

bool WindowSystem::InitSDL()
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

bool WindowSystem::Init( ISystem* pSystems )
{
	m_pSystems = pSystems;
	if(!InitSDL())
	{
		return false;
	}
	m_pSDLWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( m_pSDLWindow == NULL )
	{
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	return true;
}

void WindowSystem::Process()
{
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
		Update(nFrameTime);
		//GameLoop(nFrameTime);
		nFrameTime = SDL_GetTicks() - nStartTime;
	}
}

int WindowSystem::Update(Uint32 nFrameTime)
{
	gEnv->pGameFrameWork->PreUpdate();
	//GameLoop();
	gEnv->pGameFrameWork->PostUpdate();
	return 0;
}

void WindowSystem::ShutDown()
{
	SDL_DestroyWindow(m_pSDLWindow);
	m_pSDLWindow = NULL;

	IMG_Quit();
	SDL_Quit();

}
