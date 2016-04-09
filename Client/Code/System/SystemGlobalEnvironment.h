#ifndef _XT_SYSTEM_GLOBAL_ENVIRONMENT_H_
#define _XT_SYSTEM_GLOBAL_ENVIRONMENT_H_

#include "System/Win32/SystemWin32.h"
#include "System/Win32/GameClient.h"
#include "System/Win32/Renderer.h"


const int SCREEN_WIDTH = GetSystemMetrics ( SM_CXSCREEN );;
const int SCREEN_HEIGHT = GetSystemMetrics ( SM_CYSCREEN );

struct SSytemGlobalEnvironment
{
	ISystem* pSystem;
	IGameClient* pGameClient;
	IRenderer* pRenderer;
};
extern SSytemGlobalEnvironment* gEnv;

struct Sys_WinData
{
	SDL_Window* m_pSDLWindow;
	ProcessInfoWin32* m_pProcessInfo;
};

extern Sys_WinData gWinData;
#endif