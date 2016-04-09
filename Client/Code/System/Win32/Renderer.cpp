#include "StdAfx.h"
#include "Renderer.h"
#include <SDL_opengl.h>
#include <SDL.h>
#include <SDL_image.h>
#include "System/Win32/SystemWin32.h"
#include "System/UI/imgui_impl_sdl.h"
#include "imgui.h"

Renderer::Renderer()
{
	m_pGuiSystem = NULL;
	m_pGLContext = NULL;
}
Renderer::~Renderer()
{
	Shutdown();
	SAFE_DELETE(m_pGuiSystem);
}


bool Renderer::InitSDL()
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
		return false;
	}
	return true;
}

void Renderer::Sys_CreateWindow()
{
	assert(InitSDL());

	// Setup window
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	gWinData.m_pSDLWindow = SDL_CreateWindow( "Game Demo", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN/*SDL_WINDOW_FULLSCREEN_DESKTOP*/ );
	m_pGLContext = SDL_GL_CreateContext(gWinData.m_pSDLWindow);
}

bool Renderer::Init(ISystem* pSystems)
{
	m_pSystems = pSystems;
	m_pGuiSystem = new XT_CLIENT::GUISystem();

	Sys_CreateWindow();
	InitGuiControls();
	ImGui_ImplSdl_Init(gWinData.m_pSDLWindow);
	return true;
}

void Renderer::BeginFrame(int32 nFrameTime)
{
	ImGui_ImplSdl_NewFrame(gWinData.m_pSDLWindow);

}

void Renderer::EndFrame(int32 nFrameTime)
{
	// Rendering
	glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
	glClearColor(0xFF, 0xFF, 0xFF,0xFF);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui::Render();
	SDL_GL_SwapWindow(gWinData.m_pSDLWindow);

}

void Renderer::Shutdown()
{
	ImGui_ImplSdl_Shutdown();
	SDL_GL_DeleteContext(m_pGLContext);
	SDL_DestroyWindow(gWinData.m_pSDLWindow);
	SDL_Quit();
}

void Renderer::RenderGUI(State_Game_t eGameState)
{
	XT_CLIENT::GuiGroup* pVecControls = m_pGuiSystem->GetGroupControls(eGameState);
	if(!pVecControls)
	{
		return;
	}
	XT_CLIENT::GuiControl* pBackGround = pVecControls->backgroundControl;
	if(!pBackGround)
	{
		return;
	}
	ImGui::Begin(pBackGround->name.c_str(),0,ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse);
	ImGui::GetStyle().WindowRounding = 0;
	ImGui::SetWindowPos(ImVec2(pBackGround->posX,pBackGround->posY));
	ImGui::SetWindowSize(ImVec2(SCREEN_WIDTH,SCREEN_HEIGHT));

	XT_CLIENT::GuiGroup::ControlList* pVecAllControls = &(pVecControls->vAllControls);
	XT_CLIENT::GuiGroup::ControlList::const_iterator iter = pVecAllControls->begin();
	for(;iter!=pVecAllControls->end();++iter)
	{
		switch((*iter)->control_type)
		{
		case XT_CLIENT::Control_Image:
			{
				ImGui::SetCursorPos(ImVec2((*iter)->posX,(*iter)->posY));
				ImGui::Image((*iter)->upTexture,ImVec2((*iter)->width,(*iter)->height));
			}break;
		}
	}

	ImGui::End();
}

void Renderer::InitGuiControls()
{
	XT_CLIENT::GuiControl* pBackgroundWindow = new XT_CLIENT::GuiControl();
	pBackgroundWindow->name ="LoginFrame";
	pBackgroundWindow->control_type = XT_CLIENT::Control_BackDrop;
	pBackgroundWindow->posX = 0;
	pBackgroundWindow->posY = 0;
	m_pGuiSystem->AddBackground(STATE_LOGIN_FRAME, pBackgroundWindow);

	XT_CLIENT::GuiControl* pBackgroundImage = new XT_CLIENT::GuiControl();
	pBackgroundImage->control_type = XT_CLIENT::Control_Image;
	pBackgroundImage->posX = 0;
	pBackgroundImage->posY = 0;
	AddTexture2D(".\\Source\\9yin.jpg",&(pBackgroundImage->upTexture),pBackgroundImage->width,pBackgroundImage->height);
	//AddTexture2D("c00.png",&(pBackgroundImage->upTexture),pBackgroundImage->width,pBackgroundImage->height);
	m_pGuiSystem->AddControl(STATE_LOGIN_FRAME, pBackgroundImage);
}

void Renderer::AddTexture2D(char* path, void** pTex, int& w, int& h)
{
	//Generate texture ID
	glGenTextures( 1, &mTextureID );

	//Bind texture ID
	glBindTexture( GL_TEXTURE_2D, mTextureID );

	//Generate texture
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels );

	//Set texture parameters
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

	//Unbind texture
	glBindTexture( GL_TEXTURE_2D, NULL );

}