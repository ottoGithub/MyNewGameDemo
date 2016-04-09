#include "StdAfx.h"
#include "SystemWin32.h"
#include "Renderer.h"
SSytemGlobalEnvironment SystemWin32::m_env;

SystemWin32::SystemWin32()
{
	memset(&m_env,0,sizeof(m_env));
	m_env.pSystem = this;
}

SystemWin32::~SystemWin32()
{
	m_env.pSystem = NULL;
	Shutdown();
}



bool SystemWin32::InitRenderer()
{
	m_env.pRenderer = new Renderer();
	if(!m_env.pRenderer)
	{
		return false;
	}
	if(!m_env.pRenderer->Init(this))
	{
		SAFE_DELETE(m_env.pRenderer);
		return false;
	}
	return true;
}

bool SystemWin32::InitGameClient()
{
	m_env.pGameClient = new GameClient();
	if(!m_env.pGameClient)
	{
		return false;
	}
	if(!m_env.pGameClient->Init())
	{
		SAFE_DELETE(m_env.pGameClient);
		return false;
	}
	return true;
}

bool SystemWin32::Init()
{
//#ifdef _DEBUG
//	AllocConsole();
//	DWORD cCharsWritten;
//	std::string StartString("Win32 Console Started\n");
//	HANDLE hOutputWin = GetStdHandle(STD_OUTPUT_HANDLE);
//	WriteConsole(hOutputWin, StartString.c_str(), StartString.size(), &cCharsWritten, NULL);
//#endif

	if(!InitRenderer())
	{
		return false;
	}
	if(!InitGameClient())
	{
		return false;
	}
	//m_env.

	return true;
}

void SystemWin32::Shutdown()
{
	SAFE_DELETE(m_env.pRenderer);

//#ifdef _DEBUG
//	FreeConsole();
//#endif

}

void SystemWin32:: Process(int32 nFrameTime)
{
	PreUpdate(nFrameTime);
	Update(nFrameTime);
	PostUpdate(nFrameTime);
}

void SystemWin32::PreUpdate(int32 nFrameTime)
{
	m_env.pRenderer->BeginFrame(nFrameTime);
}

void SystemWin32::Update(int32 nFrameTime)
{
	m_env.pGameClient->Run(nFrameTime);
}

void SystemWin32::PostUpdate(int32 nFrameTime)
{
	m_env.pRenderer->EndFrame(nFrameTime);
}