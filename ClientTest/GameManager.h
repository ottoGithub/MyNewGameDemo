#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "Singleton.h"
class GameManager : public Singleton<GameManager>
{
public:
	void Tick(int nFrameTime);

	void EnterGameState(int nStateID);

	
};
#endif