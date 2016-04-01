#ifndef _XT_SYSTEM_H_
#define _XT_SYSTEM_H_


struct ProcessInfoWin32;
struct SSytemGlobalEnvironment;
class WindowSystem;
class ISystem
{
public:
	ISystem(){};
	virtual ~ISystem(){};

	virtual bool Init( ProcessInfoWin32* pProcessInfo ) = 0;
	virtual void Shutdown() = 0;

	virtual WindowSystem* GetWindowSystem() = 0;
	virtual SSytemGlobalEnvironment* GetGlobalEnvironment() = 0;

	virtual void Process() = 0;

	virtual void RenderBegin() = 0;
	virtual void Render() = 0;
	virtual void RenderEnd() = 0;
};

#endif