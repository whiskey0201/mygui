/*!
	@file
	@author		Albert Semenov
	@date		03/2010
*/
/*
	This file is part of MyGUI.

	MyGUI is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	MyGUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __MYGUI_TOOL_TIP_MANAGER_H__
#define __MYGUI_TOOL_TIP_MANAGER_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_Singleton.h"
#include "MyGUI_IUnlinkWidget.h"

namespace MyGUI
{

	class MYGUI_EXPORT ToolTipManager :
		public Singleton<ToolTipManager>,
		public IUnlinkWidget
	{
	public:
		ToolTipManager();
		virtual ~ToolTipManager();

		void initialise();
		void shutdown();

		void setDelayVisible(float _value);
		float getDelayVisible() { return mDelayVisible; }

	/*internal:*/
		void _unlinkWidget(Widget* _widget);

	private:
		void notifyEventFrameStart(float _time);

		void hideToolTip(Widget* _widget);
		void showToolTip(Widget* _widget, size_t _index, const IntPoint& _point);
		void moveToolTip(Widget* _widget, size_t _index, const IntPoint& _point);

		bool isNeedToolTip(Widget* _widget);
		size_t getToolTipIndex(Widget* _widget);

	private:
		float mDelayVisible;
		Widget* mOldFocusWidget;
		IntPoint mOldMousePoint;
		bool mToolTipVisible;
		float mCurrentTime;
		size_t mOldIndex;
		bool mNeedToolTip;

	};

}

#endif // __MYGUI_TOOL_TIP_MANAGER_H__