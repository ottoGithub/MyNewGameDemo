#ifndef _XT_GAME_CLIENT_H_
#define _XT_GAME_CLIENT_H_

#include "System/IGameClient.h"


enum State_Game_t
{
	STATE_START,
	STATE_MAIN_PAGE,
	STATE_BUSY,

	STATE_GAME_LOADING,
	STATE_GAME_INGAME,

	STATE_NUM,
};

class GameClient : public IGameClient
{
public:
	GameClient();
	virtual ~GameClient();

	virtual bool Init();
	virtual void Run();

	virtual void Shutdown();

	//on key event

private:
	State_Game_t m_LocalGameState;
};

#endif