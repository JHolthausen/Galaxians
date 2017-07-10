#pragma once

#include "Ship.h"
#include "Bullet.h"

#include <iostream>
using namespace std;
#include <Windows.h>
#include <mmsystem.h>

namespace Tmpl8{
	class SoundLibrary
	{
	public:
		SoundLibrary();
		~SoundLibrary();

		void PlayDestroy();
		void PlayBackground();
		void PlayShoot();
	};
}