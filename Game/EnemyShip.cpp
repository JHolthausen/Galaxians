#include "EnemyShip.h"

using namespace Tmpl8;				// to use template classes
using namespace glm;				// to use glm vector stuff


//default constuctor
EnemyShip::EnemyShip()
{
}

//default destructor
EnemyShip::~EnemyShip()
{
}

//switch the velocity's
void EnemyShip::TurnAround()
{
	velocity *= -1;
	formationVel *= -1;
}

//update
void EnemyShip::Update(Bullet* bullet)
{
	//keep the farmoation position updated when charging
	formationPos += formationVel;

	//if the ship is charging
	if (isCharging)
	{
		Charge(target);
	}

	//update pos with vel
	Ship::Update();

	//check if hit by bullet
	CheckbulletHit(bullet);

	//draw
	Draw();
}

void EnemyShip::CheckbulletHit(Bullet* bullet)
{
	//check for bullet hit
	if (bullet != NULL && bullet->isAlive)
	{
		//check bullet hit
		float px1 = bullet->position.x;// +(ph->bullet->width / 2);
		float py1 = bullet->position.y;// +(ph->bullet->heigth / 2);

		float px2 = position.x + width / 2;
		float py2 = position.y + height / 2;

		if (std::sqrt((pow(px2 - px1, 2) + pow(py2 - py1, 2))) < (width / 2 + width / 2))
		{
			bullet->isAlive = false;
			isHit = true;
		}
	}
	else
	{
		isHit = false;
	}
}

void EnemyShip::Charge(glm::vec2 ttarget)
{
	switch (state)
	{
	case 0:
		isCharging = true;
		this->target = ttarget;
		formationVel = velocity;
		formationPos = position;
		points *= 2;

		if (position.x > SCRWIDTH / 2)
		{
			//move right
			chargeLeft = false;
			state = 1;
			pivot = glm::vec2(position.x + r, position.y);
			q = 180;
		}
		else
		{
			//move left
			chargeLeft = true;
			state = 2;
			pivot = glm::vec2(position.x - r, position.y);
		}
		break;

		//charge right
	case 1:
		position = glm::vec2(pivot.x + this->r * std::cos(q * t), pivot.y + this->r * std::sin(q*t));

		q++;
		if (q == 360)
			state = 3;
		break;
		//charge left
	case 2:
		position = glm::vec2(pivot.x + this->r * std::cos(q * t), pivot.y + this->r * std::sin(q*t));
		q--;
		if (q <= -180)
			state = 3;
		break;
		//charge to player
	case 3:

		if (chargeLeft)
		{
			temp.x = target.x + 250 - position.x;
		}
		else
		{
			temp.x = target.x - 250 - position.x;
		}
		temp.y = target.y + 150 - position.y;

		d = std::sqrt(pow(temp.x, 2) + pow(temp.y, 2));

		//normalize vector
		velocity.y = temp.y / d * chargeSpeed;
		velocity.x = temp.x / d * chargeSpeed;

		if (position.y >= SCRHEIGHT)
		{
			state = 4;
		}

		break;
	case 4:
		//place fighter on top of screen at random
		position = glm::vec2(rand() % SCRWIDTH, -250 + rand() % 200);
		state = 5;
		break;
	case 5:
		//reset charge if true, else charge towards formation pos
		if (position.x < formationPos.x + 5 &&
			position.x > formationPos.x - 5 &&
			position.y < formationPos.y + 5 &&
			position.y > formationPos.y - 5)
		{
			position = formationPos;
			velocity = formationVel;
			state = 0;
			isCharging = false;
			points /= 2;
		}
		else
		{

			temp.x = formationPos.x - position.x;
			temp.y = formationPos.y - position.y;

			float d = std::sqrt(pow(temp.x, 2) + pow(temp.y, 2));

			velocity.y = temp.y / d * 2;
			velocity.x = temp.x / d * 2;
		}

		break;
	}
}