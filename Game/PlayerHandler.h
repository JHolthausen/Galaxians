#pragma once

#include "PlayerShip.h"
#include "game.h"
#include "ImageLibrary.h"
#include "Bullet.h"
#include "EnemyHandler.h"

#include <thread>         // std::thread

namespace Tmpl8{
	class PlayerHandler
	{
	public:

		//default constructor/destructor
		PlayerHandler(){};
		~PlayerHandler();

		//override constructor
		PlayerHandler(ImageLibrary* imgLib, Surface* screen);

		//custom functions
		void CreateShip();
		void CreateBullet();
		void PlayerInput();
		void Update();
		void Shoot();
		void PlayerHit();

		//decalre variables
		PlayerShip* p_Ship;
		ImageLibrary* imgLib;
		Surface* screen;
		Bullet* bullet = NULL;
		bool bulletFired = false;
		int lives = 3;
	};
}