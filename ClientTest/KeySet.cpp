#include "StdAfx.h"
#include "KeySet.h"

KeyDirArray::KeyDirArray()
{
}

void KeyDirArray::Push(KeyDirValue eKeyCode)
{
	std::list<int>::iterator iter = m_listKey.begin();
	for(;iter != m_listKey.end();)
	{
		if(*iter == eKeyCode)
		{
			iter = m_listKey.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	m_listKey.push_front(eKeyCode);
}

void KeyDirArray::Pull(KeyDirValue eKeyCode)
{
	std::list<int>::iterator iter = m_listKey.begin();
	while(iter != m_listKey.end())
	{
		if(*iter == eKeyCode)
		{
			iter = m_listKey.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

Vector2D KeyDirArray::GetCurKeyDirection()
{
	if(m_listKey.size() <= 0)
	{
		return Vector2D(0,0);
	}

	//std::list<int>::iterator iter = m_listKey.begin();
	//for(;iter != m_listKey.end();++iter)
	//{
	//	printf("%d\t",*iter);
	//}
	//printf("\n");


	switch(m_listKey.front())
	{
	case eDir_Up : return Vector2D(0,-1);
	case eDir_Down : return Vector2D(0,1);
	case eDir_Left : return Vector2D(-1,0);
	case eDir_Right : return Vector2D(1,0);
	}

	return Vector2D(0,0);
}

KeySet::KeySet()
{
}

Vector2D KeySet::OnDirectionKeyEvent(KeyDirValue eKeyCode, int nActionMode)
{
	if(nActionMode == eKey_Press)
	{
		m_KeyArray.Push(eKeyCode);
	}
	if(nActionMode == eKey_Up)
	{
		m_KeyArray.Pull(eKeyCode);
	}
	return m_KeyArray.GetCurKeyDirection();
}