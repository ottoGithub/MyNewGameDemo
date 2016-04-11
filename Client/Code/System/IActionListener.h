#ifndef _XT_INTERFACE_ACTION_LISTENER_H_
#define _XT_INTERFACE_ACTION_LISTENER_H_

#include <SDL.h>
class IActionListener
{
public:
	virtual void HandleAction(SDL_Event& e) = 0;
};

#endif