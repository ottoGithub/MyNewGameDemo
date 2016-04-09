#ifndef _XT_GAME_CLIENT_H_
#define _XT_GAME_CLIENT_H_

#include "System/IGameClient.h"


class GameClient : public IGameClient
{
public:
	GameClient();
	virtual ~GameClient();

	virtual bool Init();
	virtual void Run(int32 nFrameTime);

	virtual void Shutdown();

	//on key event

private:
	State_Game_t m_LocalGameState;
};

#endif