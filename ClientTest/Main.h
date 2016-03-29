#ifndef _GAME_MAIN_H_
#define _GAME_MAIN_H_

#include <stdio.h>
#include "LTexture.h"



bool InitializeEngine();
void ShutdownEngine();

// Main game functions.
bool GameInitialize();
void GameLoop(int nFrameTime);
void GameShutdown();


#endif