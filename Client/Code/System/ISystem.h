#ifndef _XT_SYSTEM_H_
#define _XT_SYSTEM_H_


struct ProcessInfoWin32;
struct SSytemGlobalEnvironment;
class ISystem
{
public:
	ISystem(){};
	virtual ~ISystem(){};

	virtual bool Init( ProcessInfoWin32* pProcessInfo ) = 0;
	virtual void Shutdown() = 0;

	virtual SSytemGlobalEnvironment* GetGlobalEnvironment() = 0;

	virtual void Process() = 0;
};

#endif