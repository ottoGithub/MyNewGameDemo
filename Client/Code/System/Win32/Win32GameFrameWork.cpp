#include "StdAfx.h"
#include "Win32GameFrameWork.h"
#include "System/Win32/SystemWin32.h"

GameFrameWorkWin32::GameFrameWorkWin32()
{
	gEnv->pGameFrameWork = this;
}

GameFrameWorkWin32::~GameFrameWorkWin32()
{
	gEnv->pGameFrameWork = NULL;
}

bool GameFrameWorkWin32::Init(ISystem* pSystem)
{
	if(!pSystem)
	{
		return false;
	}
	m_pSystem = pSystem;
	return true;
}

bool GameFrameWorkWin32::PreUpdate()
{
	m_pSystem->RenderBegin();
	return true;
}

void GameFrameWorkWin32::PostUpdate()
{
	//do sth.
	m_pSystem->Render();
	//do sth.
	m_pSystem->RenderEnd();
	//do sth.
}
