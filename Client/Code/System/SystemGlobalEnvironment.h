#ifndef _XT_SYSTEM_GLOBAL_ENVIRONMENT_H_
#define _XT_SYSTEM_GLOBAL_ENVIRONMENT_H_

#include "System/Win32/SystemWin32.h"
#include "System/Win32/Win32GameFrameWork.h"
#include "System/Win32/GameClient.h"
#include "System/Win32/Renderer.h"

struct SSytemGlobalEnvironment
{
	ISystem* pSystem;
	IGameFrameWork* pGameFrameWork;
	IGameClient* pGameClient;
	IRenderer* pRenderer;
};
extern SSytemGlobalEnvironment* gEnv;

#endif