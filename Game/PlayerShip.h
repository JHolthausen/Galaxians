#pragma once

#include "Ship.h"
#include "Bullet.h"

namespace Tmpl8{
	//inherritance
	class PlayerShip : public Ship
	{
	public:
		//deafult constructor/destructor
		PlayerShip();
		~PlayerShip();

		//override constructor
		PlayerShip(ImageLibrary* imgLib, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int heigth) : Ship(imgLib, screen, position, velocity, width, heigth){  };
		
		//override functions
		void Draw();
		void Update();
		void DrawDead();

		//custom variable
		bool isHit = false;
	};
}