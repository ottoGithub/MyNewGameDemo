#include "StdAfx.h"
#include "Main.h"
#include <stdio.h>
#include "TileClipsData.h"

#include "GameManager.h"
#include "KeyEventListenerManager.h"

bool InitializeEngine()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	//Set texture filtering to linear
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
		printf( "Warning: Linear texture filtering not enabled!" );
	}

	//Create window
	gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( gWindow == NULL )
	{
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

	//Create renderer for window
	gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if( gRenderer == NULL )
	{
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	//Initialize renderer color
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
		return false;
	}

	return true;
}

void ShutdownEngine()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

}


bool GameInitialize()
{
	if( !gTileTexture.loadFromFile( "ytty.png" ) )
	{
		printf( "Failed to load ytty texture image!\n" );
		return false;
	}
	if( !gCharacterTexture.loadFromFile( "boy.png" ) )
	{
		printf( "Failed to load Character texture image!\n" );
		return false;
	}
	InitTileClipsData();
	GameManager::Instance().EnterGameState(eGameState_LoadScene);
	return true;
}

void GameShutdown()
{
	gTileTexture.free();
	gCharacterTexture.free();
}

void GameLoop(int nFrameTime)
{
	SDL_SetRenderDrawColor( gRenderer, 0xA8, 0xB2, 0x81, 0xFF );
	SDL_RenderClear( gRenderer );

	GameManager::Instance().Tick(nFrameTime);

	//Update screen
	SDL_RenderPresent( gRenderer );
}

int main( int argc, char* args[] )
{
	if(!InitializeEngine())
	{
		printf( "Failed to initialize!\n" );
		return 1;
	}
	if(!GameInitialize())
	{
		printf( "Failed to load media!\n" );
		return 2;
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
				KeyEventListenerManager::Instance().HandlerEvent(e);
			}
		}
		nStartTime = SDL_GetTicks();
		
		GameLoop(nFrameTime);

		nFrameTime = SDL_GetTicks() - nStartTime;
	}

	// Release any and all resources.
	GameShutdown();
	ShutdownEngine();

	return 0;
}