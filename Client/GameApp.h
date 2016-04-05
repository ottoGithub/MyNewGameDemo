#ifndef _XT_GAME_APP_H_
#define _XT_GAME_APP_H_

#include "System/Win32/ProcessInfoWin32.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class ISystem;
class IGameFrameWork;
class IGameClient;
namespace XT_CLIENT
{
	class GameApp
	{
	public:
		GameApp();
		virtual ~GameApp();

		void SetProcessInfo( ProcessInfoWin32* pProcessInfo );
		void Run();
	private:
		bool Init();
		void Shutdown();
		
		bool InitSDL();
		void Sys_CreateWindow();
		
	private:
		ISystem* m_pSystem;
	};
}

#endif