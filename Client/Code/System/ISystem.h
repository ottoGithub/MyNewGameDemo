#ifndef _XT_SYSTEM_H_
#define _XT_SYSTEM_H_
#include "Types.h"

struct ProcessInfoWin32;
struct SSytemGlobalEnvironment;
class WindowSystem;
class ISystem
{
public:
	ISystem(){};
	virtual ~ISystem(){};

	virtual bool Init() = 0;
	virtual void Shutdown() = 0;

	virtual SSytemGlobalEnvironment* GetGlobalEnvironment() = 0;

	virtual void Process(int32 nFrameTime) = 0;

	virtual void PreUpdate(int32 nFrameTime) = 0;
	virtual void Update(int32 nFrameTime) = 0;
	virtual void PostUpdate(int32 nFrameTime) = 0;
};

#endif