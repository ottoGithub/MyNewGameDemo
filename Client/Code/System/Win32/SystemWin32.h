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

	virtual bool Init();
	virtual void Shutdown();

	virtual void Process();
	
	virtual SSytemGlobalEnvironment* GetGlobalEnvironment() { return &m_env;}

	virtual void RenderBegin();
	virtual void Render();
	virtual void RenderEnd();

public:
	bool InitRenderer();

protected:
	static SSytemGlobalEnvironment m_env;
};

#endif