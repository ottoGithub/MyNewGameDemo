#ifndef _XT_SYSTEM_WIN32_H_
#define _XT_SYSTEM_WIN32_H_

#include "System/ISystem.h"
#include "System/SystemGlobalEnvironment.h"
class WindowSystem;

class SystemWin32 : public ISystem
{
public:
	SystemWin32();
	virtual ~SystemWin32();

	virtual bool Init( ProcessInfoWin32* pProcessInfo );
	virtual void Shutdown();

	virtual void Process();
	
	virtual SSytemGlobalEnvironment* GetGlobalEnvironment() { return &m_env;}

protected:

	WindowSystem* m_pWindowSystem;
	SSytemGlobalEnvironment m_env;
};

#endif