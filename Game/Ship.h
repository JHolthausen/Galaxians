#pragma once
#include "GameObject.h"

namespace Tmpl8{
	//inheritance
	class Ship : public GameObject
	{
	public:
		//default constructor/destructor
		Ship();
		~Ship();

		//override constructor
		Ship(ImageLibrary* imgLab, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int heigth) : GameObject(imgLab, screen, position, velocity, width, heigth){};

		//custom function for override
		virtual void DrawDead();

	};
}