#ifndef _XT_UI_MANAGER_H_
#define _XT_UI_MANAGER_H_

#include "GUI.h"
#include "System/IGameClient.h"
#include "System/IActionListener.h"
#include <map>
#include <vector>
namespace XT_CLIENT
{
	typedef std::map< State_Game_t, GuiGroup* > GUIList;

	class GUISystem : public IActionListener
	{
	public:
		GUISystem();
		~GUISystem();

		virtual void HandleAction(SDL_Event& e);

		void AddControl(State_Game_t nGameState,GuiControl* pControl);
		void AddBackground(State_Game_t nGameState,GuiControl* pBackGround);
		GuiGroup* GetGroupControls(State_Game_t nGameState);
	private:
		GUIList m_GuiList;
	};
}

#endif