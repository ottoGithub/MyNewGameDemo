#include "StdAfx.h"
#include "GlobalValue.h"


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;


LTexture gTileTexture;
LTexture gCharacterTexture;



int gGameStateID = eGameState_LoadScene;

SDL_Rect gRectCharterAnim[WALKING_ANIMATION_DIRVALUE][WALKING_ANIMATION_FRAMES];