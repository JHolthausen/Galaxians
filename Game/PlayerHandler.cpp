#include "PlayerHandler.h"

//default constructor
PlayerHandler::PlayerHandler(ImageLibrary* imgLib, Surface* screen)
{
	this->imgLib = imgLib;
	this->screen = screen;

	CreateShip();
}

//default destructor
PlayerHandler::~PlayerHandler()
{
}

//update
void PlayerHandler::Update()
{
	PlayerInput();
	p_Ship->Update();
	p_Ship->Draw();
	PlayerHit();

	//update the player bullet if alive
	if (bullet != NULL && bullet->isAlive)
	{
		bullet->Update();
		bullet->Draw();
		if (bullet->hitEdge)
		{
			int i = 0;
			bullet->isAlive = false;
		}
	}
}

//create an bullet
void PlayerHandler::CreateBullet()
{
	int width = imgLib->bullet->GetWidth();
	int height = imgLib->bullet->GetHeight();

	glm::vec2 position = glm::vec2(p_Ship->position.x + p_Ship->width / 2 - width / 2, p_Ship->position.y + height);
	glm::vec2 velocity = glm::vec2(0.0f, -10.0f);

	bullet = new Bullet(imgLib, screen, position, velocity, width, height);

	bullet->isAlive = true;
}

//create the playership
void PlayerHandler::CreateShip()
{
	int width = imgLib->playerShip->GetWidth();
	int height = imgLib->playerShip->GetHeight();

	glm::vec2 position = glm::vec2(SCRWIDTH / 2 - width / 2, SCRHEIGHT - 100);
	glm::vec2 velocity = glm::vec2(0.0f, 0.0f);

	p_Ship = new PlayerShip(imgLib, screen, position, velocity, width, height);
}

//check for player hit
void PlayerHandler::PlayerHit()
{
	//if hit ddestroy the ship
	if (p_Ship->isHit)
	{
		p_Ship->DrawDead();
		delete p_Ship;
		lives--;
		CreateShip();
	}
}

//do somethin on input
void PlayerHandler::PlayerInput()
{
	//is arrow right pressed?
	if (GetAsyncKeyState(39)){
		p_Ship->velocity.x = 5.0f;
	}
	//is arrow left pressed?
	if (GetAsyncKeyState(37)){
		p_Ship->velocity.x = -5.0f;
	}
	//is arrow up pressed?
	if (GetAsyncKeyState(38))
	{
		Shoot();
	}
}


void PlayerHandler::Shoot()
{
	

	if (bullet == NULL)
	{
		CreateBullet();
		bulletFired = true;
	}
	else if (!bullet->isAlive)
	{
		int width = imgLib->bullet->GetWidth();
		int height = imgLib->bullet->GetHeight();

		bullet->position = glm::vec2(p_Ship->position.x + p_Ship->width / 2 - width / 2, p_Ship->position.y - height);
		bullet->isAlive = true;;
	}
}