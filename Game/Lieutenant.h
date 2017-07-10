#pragma once
#include "EnemyShip.h"

namespace Tmpl8
{
	//inheritance
	class Lieutenant : public EnemyShip
	{
	public:

		//default constructor/destructor
		Lieutenant();
		~Lieutenant();

		//override constructor
		Lieutenant(ImageLibrary* imgLab, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int heigth) : EnemyShip(imgLab, screen, position, velocity, width, heigth){};

		//override functions
		void Draw();
		void DrawDead();

		//override variables
		bool isLieutenant = true;
		int points = 60;
	};
}