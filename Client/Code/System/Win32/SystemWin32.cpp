#include "StdAfx.h"
#include "SystemWin32.h"
#include "WindowSystem.h"

SystemWin32::SystemWin32()
{
	m_pWindowSystem = NULL;
	memset(&m_env,0,sizeof(m_env));
}

SystemWin32::~SystemWin32()
{
}

bool SystemWin32::Init( ProcessInfoWin32* pProcessInfo )
{

	m_pWindowSystem = new WindowSystem();
	m_pWindowSystem->SetProcessInfo(pProcessInfo);
	if( !m_pWindowSystem->Init( this ) )
	{
		SAFE_DELETE(m_pWindowSystem);
		return false;
	}


	return true;
}

void SystemWin32::Shutdown()
{

}

void SystemWin32:: Process()
{
	m_pWindowSystem->Process();
}