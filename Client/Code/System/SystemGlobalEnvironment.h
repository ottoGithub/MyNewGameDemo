#ifndef _XT_SYSTEM_GLOBAL_ENVIRONMENT_H_
#define _XT_SYSTEM_GLOBAL_ENVIRONMENT_H_


class ISystem;
class IGameFrameWork;
struct SSytemGlobalEnvironment
{
	ISystem* pSystem;
	IGameFrameWork* pGameFrameWork;
};

#endif