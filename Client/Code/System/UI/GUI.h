#ifndef _XT_GUI_H_
#define _XT_GUI_H_

#include "Types.h"
#include <vector>

namespace XT_CLIENT
{
	enum GUI_ControlType_t
	{
		Control_BackDrop,
		Control_StaticText,
		Control_Button,
		Control_Image,
		Control_ImageButton,
	};
	struct GuiControl
	{
		std::string name;
		int control_type;
		float posX,posY;
		int width,height;
		std::string text;
		void* upTexture;
		void* downTexture;
		void* overTexture;
	};

	struct GuiGroup
	{
		typedef std::vector<GuiControl*> ControlList;
		ControlList vAllControls;
		GuiControl* backgroundControl;
	};
	/*
	enum GUI_Layer_t
	{
		Layer_Backdrop,
		Layer_Base,
		Layer_Derievd,
		Layer_Count,
	};
	const int MAX_UI_LAYER = 6;
	struct GUIControl
	{
		// Control type, id, and color.
		std::string m_name;
		int m_type;
		unsigned long m_color;

		// If text then this is the font id, else static buffer id.
		int m_listID;

		// Start pos of object, width and height of button.
		int m_xPos, m_yPos, m_width, m_height;

		// Text of static text.
		std::string *m_text;

		// Button's up, down, and over textures.
		// m_upTex also used for backdrop image.
		int m_upTex, m_downTex, m_overTex;
	};

	class GUISystem
	{
	public:
		GUISystem();
		~GUISystem();

		bool AddUIControl();
		bool AddBackdrop(int texID, int staticID);
		bool AddStaticText(int id, char *text, int x, int y,
			unsigned long color, int fontID);
		bool AddButton(int id, int x, int y, int width,
			int height, int upID, int overID,
			int downID, unsigned int staticID);
		void Shutdown();

		GUIControl *GetGUIControl(int id)
		{
			if(id < 0 || id >= m_totalControls) return NULL;
			return &m_controls[id];
		}

		GUIControl *GetBackDrop()
		{
			if(m_backDropID >= 0 && m_totalControls)
				return &m_controls[m_backDropID];

			return NULL;
		}

	private:
		std::vector<GUIControl*> m_UIControls[Layer_Count];
	};
	*/
}

#endif