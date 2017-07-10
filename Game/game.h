
//********************************************************************************************************************************
// Copyright Johan holthausen 121568 NHTV IGAD
//********************************************************************************************************************************


#pragma once
#define SCRWIDTH	800
#define SCRHEIGHT	900

#include "template.h"
#include "surface.h"

namespace Tmpl8 {
	class Surface;
	class Game
	{
	public:
		void SetTarget(Surface* _Surface) { screen = _Surface; }
		void Init();
		void Shutdown() { /* implement if you want code to be executed upon app exit */ };
		void Tick(float _DT);
		void MouseUp(int _Button) { /* implement if you want to detect mouse button presses */ }
		void MouseDown(int _Button) { /* implement if you want to detect mouse button presses */ }
		void MouseMove(int _X, int _Y) { /* implement if you want to detect mouse movement */ }
		void KeyUp(int a_Key) { /* implement if you want to handle keys */ }
		void KeyDown(int a_Key) { /* implement if you want to handle keys */ }
		void Foo();
		void Bar();
	private:
		Surface* screen;
		int state = 0;
	};
}; // namespace Tmpl8