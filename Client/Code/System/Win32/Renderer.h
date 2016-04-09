#ifndef _XT_RENDER_H_
#define _XT_RENDER_H_
#include "System/IRenderer.h"
#include <SDL.h>
#include "System/ui/GuiSystem.h"

class Renderer : public IRenderer
{
public:
	Renderer();
	virtual ~Renderer();

	virtual bool Init(ISystem* pSystems);
	virtual void Shutdown();

	virtual void BeginFrame(int32 nFrameTime);
	virtual void EndFrame(int32 nFrameTime);

	virtual void RenderGUI(State_Game_t eGameState);
private:
	bool InitSDL();
	void InitGuiControls();
	void Sys_CreateWindow();

	void AddTexture2D(char* path, void** pTex, int& w, int& h);
private:
	XT_CLIENT::GUISystem* m_pGuiSystem;
	SDL_GLContext m_pGLContext;

};
#endif