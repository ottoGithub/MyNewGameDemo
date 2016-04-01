#ifndef _XT_IGAME_CLIENT_H_
#define _XT_IGAME_CLIENT_H_


class IGameClient
{
public:
	IGameClient(){};
	virtual ~IGameClient(){};

	virtual bool Init() = 0;

	virtual void Run() = 0;

	virtual void Shutdown() = 0;

};


#endif