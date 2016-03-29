#ifndef _GLOBAL_VALUE_H_
#define _GLOBAL_VALUE_H_

#include "SDL.h"
#include "LTexture.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

const int CHARACTER_W = 32;
const int CHARACTER_H = 48;


extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;


extern LTexture gTileTexture;
extern LTexture gCharacterTexture;

enum eWalkingAnimDirection
{
	e_Down_Anim,
	e_Left_Anim,
	e_Right_Anim,
	e_Up_Anim,
	e_Walking_Ainm_Size,
};

const int WALKING_ANIMATION_FRAMES = 4;
const int WALKING_ANIMATION_DIRVALUE = e_Walking_Ainm_Size;

extern SDL_Rect gRectCharterAnim[WALKING_ANIMATION_DIRVALUE][WALKING_ANIMATION_FRAMES];



extern int gGameStateID;
enum eGameState
{
	eGameState_Start,
	eGameState_LoadScene,
};


#endif