#include "StdAfx.h"
#include <algorithm>
#include "ActionManager.h"

void ActionManager::AddListener(IActionListener* listener)
{
	if(find(m_Listeners.begin(),m_Listeners.end(),listener) == m_Listeners.end())
	{
		m_Listeners.push_back(listener);
	}
}
void ActionManager::RemoveListener(IActionListener* listener)
{
	std::vector<IActionListener*>::iterator iter = find(m_Listeners.begin(),m_Listeners.end(),listener);
	if(iter != m_Listeners.end())
	{
		m_Listeners.erase(iter);
	}
}

void ActionManager::HandleAction(SDL_Event& e)
{
	std::vector<IActionListener*>::const_iterator iter;
	for(iter = m_Listeners.begin(); iter != m_Listeners.end(); ++iter)
	{
		(*iter)->HandleAction(e);
	}
}