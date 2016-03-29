#include "stdafx.h"
#include "ActorManager.h"
#include "MyPlayer.h"

ActorManager::ActorManager()
{
}
void ActorManager::CreateActor(int guid, int nActorType)
{
	ActorMap::const_iterator iter = m_ActorMap.find(guid);
	if(iter != m_ActorMap.end())
	{
		return;
	}
	Actor* pActor = NULL;
	//pActor->InitialComponents();
	if(nActorType == ObjType_MyPlayer)
	{
		pActor = new MyPlayer();
		pActor->SetGuid(guid);
		m_pMyPlayer = (MyPlayer*)pActor;
	}
	m_ActorMap.insert(ActorMap::value_type(guid,pActor));
}

void ActorManager::Tick(int nFramTime)
{
	ActorMap::const_iterator iter = m_ActorMap.begin();
	for(;iter!=m_ActorMap.end();++iter)
	{
		iter->second->Tick(nFramTime);
	}
}

Actor* ActorManager::GetActorByGuid(int guid)
{		
	ActorMap::const_iterator iter = m_ActorMap.begin();
	for(;iter!=m_ActorMap.end();++iter)
	{
		if(iter->first == guid)
		{
			return iter->second;
		}
	}
	return NULL;
}