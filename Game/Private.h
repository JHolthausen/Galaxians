#pragma once
#include "EnemyShip.h"

namespace Tmpl8{
	//inherritance
	class Private : public EnemyShip
	{
	public:
		//default constructor/destructor
		Private();
		~Private();

		//override constructor
		Private(ImageLibrary* imgLab, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int heigth) : EnemyShip(imgLab, screen, position, velocity, width, heigth){};
		
		//override functions
		void Draw();
		void DrawDead();
	};
}