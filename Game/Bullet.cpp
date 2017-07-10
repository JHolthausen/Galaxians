#include "Bullet.h"

using namespace Tmpl8;				// to use template classes
using namespace glm;				// to use glm vector stuff


// Default constructor.
Bullet::Bullet()
{
}

// Default destructor.
Bullet::~Bullet()
{
}

// Draw function - Overrides parent.
void Bullet::Draw()
{
	// Draw the bullet image. 
	imgLib->bullet->CopyTo(screen, (int)position.x, (int)position.y);
}


// Check if the bullet has hit the player with circular hit detection.
bool Bullet::PlayerHit(PlayerShip* p_Ship)
{
	// Set variables for colculations.
	float px1 = p_Ship->GetMiddleVec().x;
	float py1 = p_Ship->GetMiddleVec().y;

	float px2 = GetMiddleVec().x;
	float py2 = GetMiddleVec().y;

	// Check if the distance of both points is les than the *radius = (width/2).
	// True == hit.
	// False == no hit.
	if (std::sqrt((pow(px2 - px1, 2) + pow(py2 - py1, 2))) < (width + p_Ship->width))
	{
		return true;
	}

	else
	{
		return false;
	}
}