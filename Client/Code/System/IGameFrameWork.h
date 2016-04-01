#ifndef _XT_GAME_FRAMEWORK_H_
#define _XT_GAME_FRAMEWORK_H_

class ISystem;
class IGameFrameWork
{
public:
	IGameFrameWork(){}
	virtual ~IGameFrameWork(){}
	
	virtual bool Init(ISystem* pSystem) = 0;

	virtual bool PreUpdate() = 0;
	virtual void PostUpdate() = 0; 

protected:
	ISystem* m_pSystem;

};

#endif