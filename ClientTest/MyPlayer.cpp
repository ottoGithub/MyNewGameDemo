#include "StdAfx.h"
#include "MyPlayer.h"
#include "KeySet.h"

MyPlayer::MyPlayer()
{
	ADD_TO_KEYEVENT_LISTENER(this);
}

MyPlayer::~MyPlayer()
{
	REMOVE_FROM_KEYEVENT_LISTENER(this);
}

void MyPlayer::Tick(int nFrameTime)
{
	//CalculateDirection();
	Actor::Tick(nFrameTime);
}

void MyPlayer::PostKeyEvent(SDL_Event& e)
{
	//当事件为失去窗口焦点时，是不是要做处理？
	if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			{
				m_vDir = KeySet::Instance().OnDirectionKeyEvent(eDir_Up,eKey_Press);
				return;
			}
		case SDL_SCANCODE_S:
			{
				m_vDir = KeySet::Instance().OnDirectionKeyEvent(eDir_Down,eKey_Press);
				return;
			}
		case SDL_SCANCODE_A:
			{
				m_vDir = KeySet::Instance().OnDirectionKeyEvent(eDir_Left,eKey_Press);
				return;
			}
		case SDL_SCANCODE_D:
			{
				m_vDir = KeySet::Instance().OnDirectionKeyEvent(eDir_Right,eKey_Press);
				return;
			}
		default:
			return;
		}
	}
	if(e.type == SDL_KEYUP)
	{
		switch(e.key.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			{
				m_vDir = KeySet::Instance().OnDirectionKeyEvent(eDir_Up,eKey_Up);
				return;
			}
		case SDL_SCANCODE_S:
			{
				m_vDir = KeySet::Instance().OnDirectionKeyEvent(eDir_Down,eKey_Up);
				return;
			}
		case SDL_SCANCODE_A:
			{
				m_vDir = KeySet::Instance().OnDirectionKeyEvent(eDir_Left,eKey_Up);
				return;
			}
		case SDL_SCANCODE_D:
			{
				m_vDir = KeySet::Instance().OnDirectionKeyEvent(eDir_Right,eKey_Up);
				return;
			}
		default:
			return;
		}
	}
}

//void MyPlayer::CalculateDirection()
//{
//	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
//	if( currentKeyStates[ SDL_SCANCODE_W ] )
//	{
//		m_vDir = Vector2D(0,-1);
//	}
//	else if( currentKeyStates[ SDL_SCANCODE_S ] )
//	{
//		m_vDir = Vector2D(0,1);
//	}
//	else if( currentKeyStates[ SDL_SCANCODE_A ] )
//	{
//		m_vDir = Vector2D(-1,0);
//	}
//	else if( currentKeyStates[ SDL_SCANCODE_D ] )
//	{
//		m_vDir = Vector2D(1,0);
//	}
//	else
//	{
//		m_vDir = Vector2D(0,0);
//	}
//}