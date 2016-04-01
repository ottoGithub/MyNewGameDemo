#include "StdAfx.h"
#include "Renderer.h"
#include "System/Win32/SystemWin32.h"
#include "System/Win32/WindowSystem.h"

Renderer::Renderer()
{
	m_pSDLRenderer = NULL;
}
Renderer::~Renderer()
{
	Shutdown();
}

bool Renderer::Init(ISystem* pSystems)
{
	m_pSystems = pSystems;
	m_pSDLRenderer = SDL_CreateRenderer( m_pSystems->GetWindowSystem()->GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if(!m_pSDLRenderer)
	{
		return false;
	}
	SDL_SetRenderDrawColor( m_pSDLRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	return true;
}

void Renderer::BeginFrame()
{
	SDL_SetRenderDrawColor( m_pSDLRenderer, 0xA8, 0xB2, 0x81, 0xFF );
	SDL_RenderClear( m_pSDLRenderer );
}

void Renderer::EndFrame()
{
	SDL_RenderPresent( m_pSDLRenderer );
}

void Renderer::Shutdown()
{
	SDL_DestroyRenderer( m_pSDLRenderer );
	m_pSDLRenderer = NULL;
}