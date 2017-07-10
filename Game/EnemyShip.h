#pragma once

#include "ship.h"
#include "Bullet.h"

namespace Tmpl8{

	//inherrit from ship
	class EnemyShip : public Ship
	{
	public:

		//default constructor/destructor
		EnemyShip();
		~EnemyShip();

		//override constructor
		EnemyShip(ImageLibrary* imgLab, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int heigth) : Ship(imgLab, screen, position, velocity, width, heigth){};

		//override parent
		void Update(Bullet* bullet);

		//custom functions
		void TurnAround();
		void Charge(glm::vec2 target);
		void CheckbulletHit(Bullet* bullet);

		//declare variables
		bool isHit = false;

		//position in fomation
		glm::vec2 formationPos;
		glm::vec2 formationVel = glm::vec2(0.0f, 0.0f);

		//values for charge
		bool isCharging = false;
		glm::vec2 pivot;
		int r = 75;
		int chargeSpeed = 2;
		float t = PI / 180; // pi is declared in template
		double q = 1;
		int state = 0;
		glm::vec2 target;
		int j;
		glm::vec2 temp;
		float d;
		bool chargeLeft = false;
		bool bulletsAlive = false;

		//default variable used by childs
		bool isLieutenant = false;
		bool isSergeant = false;
		int points = 30;
	};
}