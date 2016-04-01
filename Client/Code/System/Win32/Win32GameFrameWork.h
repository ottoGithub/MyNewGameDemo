#ifndef _XT_WIN32_GAME_FRAMEWORK_H_
#define _XT_WIN32_GAME_FRAMEWORK_H_

#include "System/IGameFrameWork.h"

class ISystem;

class GameFrameWorkWin32 : public IGameFrameWork
{
public:
	GameFrameWorkWin32();
	virtual ~GameFrameWorkWin32();

	bool Init(ISystem* pSystem);

	bool PreUpdate();
	void PostUpdate();
};

#endif