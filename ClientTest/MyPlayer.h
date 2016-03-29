#ifndef _MYPLAYER_H_
#define _MYPLAYER_H_

#include "Actor.h"
#include "KeyEventListenerManager.h"

class MyPlayer : public Actor, public IEventListener
{
public:
	MyPlayer();
	~MyPlayer();
	void Tick(int nFrameTime);
	void PostKeyEvent(SDL_Event& e);

public:
	//void CalculateDirection();
};
#endif