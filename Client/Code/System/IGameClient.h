#ifndef _XT_IGAME_CLIENT_H_
#define _XT_IGAME_CLIENT_H_

#include "Types.h"
enum State_Game_t
{
	STATE_START,
	STATE_LOGIN_FRAME,
	STATE_BUSY,

	STATE_GAME_LOADING,
	STATE_GAME_INGAME,

	STATE_NUM,
};


class IGameClient
{
public:
	IGameClient(){};
	virtual ~IGameClient(){};

	virtual bool Init() = 0;

	virtual void Run(int32 nFrameTime) = 0;

	virtual void Shutdown() = 0;

};


#endif