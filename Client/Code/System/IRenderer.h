#ifndef _XT_I_RENDERER_H_
#define _XT_I_RENDERER_H_

class IRenderer
{
public:
	IRenderer(){}
	virtual ~IRenderer(){}

	virtual bool Init(ISystem* pSystems) = 0;
	virtual void Shutdown() = 0;

	virtual void BeginFrame() = 0;
	virtual void EndFrame() = 0;
protected:
	ISystem* m_pSystems;
};

#endif