#pragma once

#include "GameObject.h"			// To use parent.
#include "PlayerShip.h"			// Used for checking collision.

namespace Tmpl8{
	class PlayerShip;	// Needed for the use of PlayerShip  ** w/o givess error **

	// Inherrit from GameObject.
	class Bullet : public GameObject
	{
	public:

		// Default Constructor & Destructor.
		Bullet();
		~Bullet();

		// Constructor override and Parent constructer used.
		Bullet(ImageLibrary* imgLib, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int heigth) : GameObject(imgLib, screen, position, velocity, width, heigth){};
		
		
		// Override parent Draw() function.
		void Draw();

		// Custom functions.
		bool PlayerHit(PlayerShip* p_Ship);

		// Declare variables
		bool isAlive = false;
	};
}