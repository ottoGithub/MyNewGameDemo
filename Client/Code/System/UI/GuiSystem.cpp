#include "StdAfx.h"
#include "System/ui/GuiSystem.h"

namespace XT_CLIENT
{
	GUISystem::GUISystem()
	{
	}

	GUISystem::~GUISystem()
	{

	}

	void GUISystem::AddControl(State_Game_t nGameState, GuiControl* pControl)
	{
		GUIList::iterator iter = m_GuiList.find(nGameState);
		if(iter != m_GuiList.end())
		{
			iter->second->vAllControls.push_back(pControl);
		}
		else
		{
			GuiGroup* pGuiGroup = new GuiGroup();
			pGuiGroup->vAllControls.push_back(pControl);
			m_GuiList.insert(GUIList::value_type(nGameState,pGuiGroup));
		}
	}

	GuiGroup* GUISystem::GetGroupControls(State_Game_t nGameState)
	{
		assert(m_GuiList.size() > 0);
		GUIList::iterator iter = m_GuiList.find(nGameState);
		if(iter != m_GuiList.end())
		{
			return iter->second;
		}
		return NULL;
	}

	void GUISystem::AddBackground(State_Game_t nGameState,GuiControl* pBackGround)
	{
		GUIList::iterator iter = m_GuiList.find(nGameState);
		if(iter != m_GuiList.end())
		{
			iter->second->backgroundControl = pBackGround;
		}
		else
		{
			GuiGroup* pGuiGroup = new GuiGroup();
			pGuiGroup->backgroundControl = pBackGround;
			m_GuiList.insert(GUIList::value_type(nGameState,pGuiGroup));
		}
	}
}