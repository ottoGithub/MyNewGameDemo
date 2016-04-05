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

void SystemWin32:: Process()
{
}

void SystemWin32::RenderBegin()
{
	m_env.pRenderer->BeginFrame();
}

void SystemWin32::Render()
{

}

void SystemWin32::RenderEnd()
{
	m_env.pRenderer->EndFrame();
}