#ifndef _XT_GAME_FRAMEWORK_H_
#define _XT_GAME_FRAMEWORK_H_

class IGameFrameWork
{
public:
	IGameFrameWork(){}
	virtual ~IGameFrameWork(){}
	
	virtual bool Init() = 0;

	virtual bool PreUpdate() = 0;
	virtual void PostUpdate() = 0; 

};

#endif