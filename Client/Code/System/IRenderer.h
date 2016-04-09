#ifndef _XT_I_RENDERER_H_
#define _XT_I_RENDERER_H_

#include "System/SystemGlobalEnvironment.h"

class IRenderer
{
public:
	IRenderer(){}
	virtual ~IRenderer(){}

	virtual bool Init(ISystem* pSystems) = 0;
	virtual void Shutdown() = 0;

	virtual void BeginFrame(int32 nFrameTime) = 0;
	virtual void EndFrame(int32 nFrameTime) = 0;

	virtual void RenderGUI(State_Game_t eGameState) = 0;

protected:
	ISystem* m_pSystems;
};

#endif