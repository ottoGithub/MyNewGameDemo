#ifndef _XT_GAME_APP_H_
#define _XT_GAME_APP_H_

#include "System/Win32/ProcessInfoWin32.h"

class ISystem;
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
		ProcessInfoWin32* m_pProcessInfo;
		ISystem* m_pSystem;
	};
}

#endif