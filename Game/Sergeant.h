#pragma once

#include "EnemyShip.h"

namespace Tmpl8
{
	//inherritance
	class Sergeant : public EnemyShip
	{
	public:
		//default constructor/destructor
		Sergeant();
		~Sergeant();

		//override constructor
		Sergeant(ImageLibrary* imgLab, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int heigth) : EnemyShip(imgLab, screen, position, velocity, width, heigth){ isSergeant = true; };
		
		//override functions
		void Draw();
		void DrawDead();

		//override variable
		int points = 40;
	};
}