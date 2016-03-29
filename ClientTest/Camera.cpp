#include "StdAfx.h"
#include "Camera.h"
#include "ActorManager.h"
#include "SceneManager.h"

Camera::Camera():m_vCamPos(0,0),CameraViewHeight(SCREEN_HEIGHT),CameraViewWidth(SCREEN_WIDTH)
{
	m_nLinkID = 0;
}

Camera::~Camera()
{

}

void Camera::Tick(int nFrameTime)
{
	UpdateCameraPos();

	Render();
}

void Camera::Render()
{
	RenderCameraView();
	RenderActor();
}

void Camera::RenderActor()
{
	Actor* pActor = ActorManager::Instance().GetActorByGuid(m_nLinkID);
	if(!pActor)
	{
		return;
	}
	pActor->RenderActor(m_RectView);
}

void Camera::RenderCameraView()
{
	SceneManager::Instance().RenderScene(m_RectView);
}

void Camera::SetLinkEntity(int nID)
{
	 m_nLinkID = nID;
	 UpdateCameraPos();
}

void Camera::GetValidRect(int& x, int& y ,int w, int h, int xMax, int yMax)
{
	if(x < 0)
	{
		x = 0;
	}
	if(y < 0)
	{
		y = 0;
	}

	if(w > xMax)
	{
		x = w/2;
	}
	else
	{
		if( x + w > xMax)
		{
			x = xMax - w;
		}
	}

	if(h > yMax)
	{
		y = h/2;
	}
	else
	{
		if( y + h > yMax)
		{
			y = yMax - h;
		}
	}

}
void Camera::UpdateCameraPos()
{
	Actor* pActor = ActorManager::Instance().GetActorByGuid(m_nLinkID);
	if(!pActor)
	{
		return;
	}
	m_vCamPos = pActor->GetPos();

	m_RectView.x = int(m_vCamPos.x - CameraViewWidth/2);
	m_RectView.y = int(m_vCamPos.y - CameraViewHeight/2);
	m_RectView.h = CameraViewHeight;
	m_RectView.w = CameraViewWidth;
	GetValidRect(m_RectView.x, m_RectView.y, m_RectView.w, m_RectView.h, LEVEL_WIDTH, LEVEL_HEIGHT);
}
