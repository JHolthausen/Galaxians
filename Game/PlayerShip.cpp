#include "PlayerShip.h"

//default constructor
PlayerShip::PlayerShip()
{
}

//default destructor
PlayerShip::~PlayerShip()
{
}

//update
void PlayerShip::Update()
{
	//do parnet update
	Ship::Update();

	//if ship hit edge place it velocity *-1 back
	if (hitEdge)
	{
		velocity *= -1;
		position += velocity;
	}
	//set velocity to 0 to prevent non keyinput movement
	velocity = glm::vec2(0.0f, 0.0f);
}

//override parent draw
void PlayerShip::Draw()
{
	imgLib->playerShip->CopyTo(screen, (int)position.x, (int) position.y);
}

//override parent drawdead
void PlayerShip::DrawDead()
{
	imgLib->i_playerDead->CopyTo(screen, (int)position.x, (int) position.y);
}