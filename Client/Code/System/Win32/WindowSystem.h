#ifndef _XT_WINDOW_SYSTEM_H_
#define _XT_WINDOW_SYSTEM_H_

class ISystem;
struct ProcessInfoWin32;
struct SDL_Window;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class WindowSystem
{
public:
	WindowSystem();
	virtual ~WindowSystem();

	virtual void SetProcessInfo(ProcessInfoWin32* pProcessInfo);
	virtual bool Init( ISystem* pSystems );
	virtual void Process();
	virtual void ShutDown();

	virtual int Update();

protected:
	ProcessInfoWin32* m_pProcessInfo;
	ISystem* m_pSystems;

	SDL_Window* m_pSDLWindow;
};

#endif