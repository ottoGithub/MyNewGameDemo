#ifndef _XT_RENDER_H_
#define _XT_RENDER_H_
#include "System/IRenderer.h"
#include <SDL.h>

class Renderer : public IRenderer
{
public:
	Renderer();
	virtual ~Renderer();

	virtual bool Init(ISystem* pSystems);
	virtual void Shutdown();

	virtual void BeginFrame();
	virtual void EndFrame();
protected:

	SDL_Renderer* m_pSDLRenderer;
};
#endif