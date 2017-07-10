#pragma once

#include "EnemyShip.h"  // to use parent.

namespace Tmpl8
{
	// Inherrit from EnemyShip.
	class Corporal : public EnemyShip
	{
	public:

		// Default Constructor & Destructor.
		Corporal();
		~Corporal();

		// Constructor override and Parent constructer used.
		Corporal(ImageLibrary* imgLab, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int heigth) : EnemyShip(imgLab, screen, position, velocity, width, heigth){};
		
		// Override parent functions.
		void DrawDead();
		void Draw();

		// Override Parent points
		int points = 50;
	};
}
