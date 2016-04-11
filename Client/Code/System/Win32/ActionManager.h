#ifndef _XT_ACTION_MANAGER_H_
#define _XT_ACTION_MANAGER_H_
#include "System/IActionListener.h"
#include <vector>
#include <Singleton.h>

class ActionManager : public Singleton<ActionManager>
{
public:
	void AddListener(IActionListener* listener);
	void RemoveListener(IActionListener* listener);

	void HandleAction(SDL_Event& e);
private:
	std::vector<IActionListener*> m_Listeners;
};

#define ADD_ACTION(a) ActionManager::Instance().AddListener(a)

#define REMOVE_ACTION(a) ActionManager::Instance().RemoveListener(a)

#endif