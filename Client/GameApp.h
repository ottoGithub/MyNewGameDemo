#ifndef _XT_GAME_APP_H_
#define _XT_GAME_APP_H_

#include "System/Win32/ProcessInfoWin32.h"

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
	protected:
		bool Init();
		void Shutdown();

	protected:
		ISystem* m_pSystem;

		ProcessInfoWin32* m_pProcessInfo;
		IGameFrameWork* m_pGameFrameWork;
		IGameClient* m_pGameClient;
	};
}

#endif