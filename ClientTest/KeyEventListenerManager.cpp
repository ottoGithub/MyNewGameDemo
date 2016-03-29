#include "StdAfx.h"
#include <algorithm>
#include "KeyEventListenerManager.h"

void KeyEventListenerManager::AddListener(IEventListener* listener)
{
	if(find(m_Listeners.begin(),m_Listeners.end(),listener) == m_Listeners.end())
	{
		m_Listeners.push_back(listener);
	}
}
void KeyEventListenerManager::RemoveListener(IEventListener* listener)
{
	std::vector<IEventListener*>::iterator iter = find(m_Listeners.begin(),m_Listeners.end(),listener);
	if(iter != m_Listeners.end())
	{
		m_Listeners.erase(iter);
	}
}

void KeyEventListenerManager::HandlerEvent(SDL_Event& e)
{
	std::vector<IEventListener*>::const_iterator iter;
	for(iter = m_Listeners.begin(); iter != m_Listeners.end(); ++iter)
	{
		(*iter)->PostKeyEvent(e);
	}
}