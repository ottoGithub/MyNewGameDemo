#include "StdAfx.h"
#include "GUI.h"

namespace XT_CLIENT
{
	/*
	GUISystem::GUISystem()
	{

	}

	GUISystem::~GUISystem()
	{ 
		Shutdown();
	}

	bool GUISystem::AddBackdrop(int texID, int sID)
	{
		if(texID < 0 || sID < 0) 
		{
			return false;
		}
		GUIControl* pCtrl = new GUIControl;
		//pCtrl->

		return true;
	}


	bool GUISystem::AddStaticText(int id, char *text, int x, int y,
		unsigned long color, int fontID)
	{
		if(!text || fontID < 0) 
		{
			return false;
		}

		// Fill it with all the info we need for static text.
		//m_controls[m_totalControls].m_type = UGP_GUI_STATICTEXT;
		m_controls[m_totalControls].m_id = id;
		m_controls[m_totalControls].m_color = color;
		m_controls[m_totalControls].m_xPos = x;
		m_controls[m_totalControls].m_yPos = y;
		m_controls[m_totalControls].m_listID = fontID;

		// Copy text data.
		int len = strlen(text);
		m_controls[m_totalControls].m_text = new char[len + 1];
		if(!m_controls[m_totalControls].m_text) return false;
		memcpy(m_controls[m_totalControls].m_text, text, len); 
		m_controls[m_totalControls].m_text[len] = '\0';

		// Increment total.
		m_totalControls++;

		return true;
	}


	bool GUISystem::AddButton(int id, int x, int y, int width,
		int height, int upID, int overID,
		int downID, unsigned int staticID)
	{
		// Create a blank control.
		if(!IncreaseControls()) return false;

		// Set all the data needed to render/process a button.
		m_controls[m_totalControls].m_type = UGP_GUI_BUTTON;
		m_controls[m_totalControls].m_id = id;
		m_controls[m_totalControls].m_xPos = x;
		m_controls[m_totalControls].m_yPos = y;
		m_controls[m_totalControls].m_width = width;
		m_controls[m_totalControls].m_height = height;
		m_controls[m_totalControls].m_upTex = upID;
		m_controls[m_totalControls].m_overTex = overID;
		m_controls[m_totalControls].m_downTex = downID;
		m_controls[m_totalControls].m_listID = staticID;

		// Increment total.
		m_totalControls++;

		return true;
	}


	void GUISystem::Shutdown()
	{
		// Release all resources.
		for(int s = 0; s < m_totalControls; s++)
		{
			if(m_controls[s].m_text)
			{
				delete[] m_controls[s].m_text;
				m_controls[s].m_text = NULL;
			}
		}

		m_totalControls = 0;
		if(m_controls) delete[] m_controls;
		m_controls = NULL;
	}
	*/
}