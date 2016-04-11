#include "StdAfx.h"
#include "Renderer.h"
#include <SDL_opengl.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_main.h>
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
	gWinData.m_pSDLWindow = SDL_CreateWindow( "Game Demo", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS );
	m_pGLContext = SDL_GL_CreateContext(gWinData.m_pSDLWindow);
}

bool Renderer::Init(ISystem* pSystems)
{
	m_pSystems = pSystems;
	m_pGuiSystem = new XT_CLIENT::GUISystem();

	Sys_CreateWindow();
	ImGui_ImplSdl_Init(gWinData.m_pSDLWindow);
	InitGuiControls();
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
		ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
	ImGui::GetStyle().WindowRounding = 0;
	ImGui::GetStyle().WindowPadding = ImVec2(0, 0);
	ImGui::SetWindowPos(ImVec2(float(pBackGround->posX),float(pBackGround->posY) ));
	ImGui::SetWindowSize(ImVec2(float(pBackGround->width),float(pBackGround->height) ));

	XT_CLIENT::GuiGroup::ControlList* pVecAllControls = &(pVecControls->vAllControls);
	XT_CLIENT::GuiGroup::ControlList::const_iterator iter = pVecAllControls->begin();
	for(;iter!=pVecAllControls->end();++iter)
	{
		switch((*iter)->control_type)
		{
		case XT_CLIENT::Control_Image:
			{
				ImGui::SetCursorPos(ImVec2((*iter)->posX,(*iter)->posY));
				ImGui::Image((*iter)->upTexture,ImVec2(float((*iter)->width),float((*iter)->height)));
			}break;
		case XT_CLIENT::Control_Button:
			{
				ImGui::SetCursorPos(ImVec2((*iter)->posX,(*iter)->posY));
				if (ImGui::Button( ((*iter)->text).c_str()) )
				{
					//Reg Call Back Event
					SDL_Event ev;
					ev.type = SDL_QUIT;
					SDL_PushEvent(&ev);
				}
			}break;
		case XT_CLIENT::Control_ImageButton:
			{
				ImGui::SetCursorPos(ImVec2((*iter)->posX,(*iter)->posY));
				//ImGui::PushStyleVar(ImGuiStyleVar_Alpha,1);
				ImGui::PushStyleColor(ImGuiCol_Button,ImVec4(0,0,0,0));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered,ImVec4(0,0,0,0));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive,ImVec4(0,0,0,0));
				if(ImGui::ImageButton(((*iter)->upTexture),ImVec2(float((*iter)->width),float((*iter)->height)) ) )
				{
					SDL_Event ev;
					ev.type = SDL_QUIT;
					SDL_PushEvent(&ev);
				}
				ImGui::PopStyleColor(3);
				//ImGui::PopStyleVar();
			}break;
		}
	}

#ifdef _DEBUG
	POINT pt;
	GetCursorPos(&pt);
	ImGui::SetCursorPos(ImVec2(10,3));
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::SetCursorPos(ImVec2(10,18));
	ImGui::Text("cursor position %d,%d", pt.x,pt.y);
#endif

	ImGui::End();
}

void Renderer::InitGuiControls()
{
	XT_CLIENT::GuiControl* pBackgroundWindow = new XT_CLIENT::GuiControl();
	pBackgroundWindow->name ="LoginFrame";
	pBackgroundWindow->control_type = XT_CLIENT::Control_BackDrop;
	pBackgroundWindow->posX = 0;
	pBackgroundWindow->posY = 0;
	pBackgroundWindow->width = SCREEN_WIDTH;
	pBackgroundWindow->height = SCREEN_HEIGHT;
	m_pGuiSystem->AddBackground(STATE_LOGIN_FRAME, pBackgroundWindow);

	XT_CLIENT::GuiControl* pBackgroundImage = new XT_CLIENT::GuiControl();
	pBackgroundImage->name = "LoginFrame_BackGround";
	pBackgroundImage->control_type = XT_CLIENT::Control_Image;
	pBackgroundImage->posX = 0;
	pBackgroundImage->posY = 0;
	AddTexture2D(".\\Source\\9yin.jpg",&(pBackgroundImage->upTexture),pBackgroundImage->width,pBackgroundImage->height);
	pBackgroundImage->width = SCREEN_WIDTH;
	pBackgroundImage->height = SCREEN_HEIGHT;
	m_pGuiSystem->AddControl(STATE_LOGIN_FRAME, pBackgroundImage);

	XT_CLIENT::GuiControl* pImageButtonClose = new XT_CLIENT::GuiControl();
	pImageButtonClose->name = "LoginFrame_ButtonClose";
	pImageButtonClose->control_type = XT_CLIENT::Control_ImageButton;
	pImageButtonClose->posX = 0.975f * SCREEN_WIDTH;
	pImageButtonClose->posY = 0;
	AddTexture2D(".\\Source\\Button\\up.png",&(pImageButtonClose->upTexture),pImageButtonClose->width,pImageButtonClose->height);
	AddTexture2D(".\\Source\\Button\\over.png",&(pImageButtonClose->overTexture),pImageButtonClose->width,pImageButtonClose->height);
	m_pGuiSystem->AddControl(STATE_LOGIN_FRAME, pImageButtonClose);
}


/*
void Renderer::AddTexture2D(char* path, void** pTex, int& w, int& h)
{
	BITMAP bm;
	GLuint idTexture = 0;
	CImage img;             //需要头文件atlimage.h  
	HRESULT hr = img.Load(path);
	if (!SUCCEEDED(hr))   //文件加载失败  
	{
		return;
	}
	HBITMAP hbmp = img;
	if (!GetObject(hbmp, sizeof(bm), &bm))
		return;
	glGenTextures(1, &idTexture);
	if (idTexture)
	{
		glBindTexture(GL_TEXTURE_2D, idTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glPixelStoref(GL_PACK_ALIGNMENT, 1);
		/ *
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, bm.bmWidth, bm.bmHeight, 0, -1, 1);
		* /
		glTexImage2D(GL_TEXTURE_2D, 0, 3, bm.bmWidth, bm.bmHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, bm.bmBits); //这里不是GL_RGB  
	}
	else
	{
		GLenum n = glGetError();
	}
	*pTex = (void *)(intptr_t)idTexture;
	w = bm.bmWidth;
	h = bm.bmHeight;
}*/

void Renderer::AddTexture2D(char* path, void** pTex, int& w, int& h)
{
	GLuint idTexture = 0;
	SDL_Surface* loadedSurface = IMG_Load(path);
	if(!loadedSurface)
	{
		return;
	}
	w = loadedSurface->w;
	h = loadedSurface->h;
	int mode;
	if (loadedSurface->format->BytesPerPixel == 3) { // RGB 24bit
		mode = GL_RGB;
	} else if (loadedSurface->format->BytesPerPixel == 4) { // RGBA 32bit
		mode = GL_RGBA;
	} else {
		SDL_FreeSurface(loadedSurface);
		return;
	}
	glGenTextures(1, &idTexture);
	if (idTexture)
	{
		glBindTexture(GL_TEXTURE_2D, idTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glPixelStoref(GL_PACK_ALIGNMENT, 1);
		glTexImage2D(GL_TEXTURE_2D, 0, mode, w, h, 0, mode, GL_UNSIGNED_BYTE, loadedSurface->pixels); //这里不是GL_RGB  
	}
	*pTex = (void *)(intptr_t)idTexture;
	SDL_FreeSurface(loadedSurface);
}
