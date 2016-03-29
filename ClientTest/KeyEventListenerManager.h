#ifndef _KEY_EVENT_LISTENER_MNG_H_
#define _KEY_EVENT_LISTENER_MNG_H_
#include <vector>
#include "Singleton.h"

class IEventListener
{
public:
	virtual void PostKeyEvent(SDL_Event& e) = 0;
};

class KeyEventListenerManager : public Singleton<KeyEventListenerManager>
{
public:
	void AddListener(IEventListener* listener);
	void RemoveListener(IEventListener* listener);

	void HandlerEvent(SDL_Event& e);
private:
	std::vector<IEventListener*> m_Listeners;
};


#define ADD_TO_KEYEVENT_LISTENER(a) KeyEventListenerManager::Instance().AddListener(a)

#define REMOVE_FROM_KEYEVENT_LISTENER(a) KeyEventListenerManager::Instance().RemoveListener(a)

#endif