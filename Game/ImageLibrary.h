#pragma once

#include "template.h"
#include "surface.h"

using namespace Tmpl8;				// to use template classes
using namespace glm;				// to use glm vector stuff

namespace Tmpl8
{
	class ImageLibrary
	{
	public:
		ImageLibrary();
		~ImageLibrary();

		Surface* ball;

		Surface* playerShip;
		Surface* bullet;

		//enemy's
		Surface* i_Sergeant;
		Surface* i_Private;
		Surface* i_Corporal;
		Surface* i_Lieutenant;

		Surface* i_CorporalDead;
		Surface* i_SergeantDead;
		Surface* i_PrivateDead;
		Surface* i_LieutenantDead;

		Surface* i_playerDead;

		//gui
		Surface* flag;
	};
}
