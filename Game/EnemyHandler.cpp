#include "EnemyHandler.h"

// Default Constructer.
EnemyHandler::EnemyHandler()
{
}

//Default destructor.
EnemyHandler::~EnemyHandler()
{
}

// Override constructer.
EnemyHandler::EnemyHandler(ImageLibrary* imgLib, Surface* screen)
{
	this->imgLib = imgLib;
	this->screen = screen;

	enemyFormStart = glm::vec2(100.0f, 250.0f);
	CreateFormation();
}



//create the formation of enemy's
void EnemyHandler::CreateFormation()
{
	//an int wich holds the amount of lt. alive
	lieutenantsAlive = 2;

	//al ships are the same size, size is determent by the image size
	int width = imgLib->i_Private->GetWidth();
	int height = imgLib->i_Private->GetHeight();

	// declare velocity
	glm::vec2 velocity = glm::vec2(1.0f, 0.0f);
	
	// set position on screen - is repeated every row
	glm::vec2 position = glm::vec2(enemyFormStart.x, enemyFormStart.y);

	//create new ship with declared variable, above
	EnemyShip* temp = new Private(imgLib, screen, position, velocity, width, height);

	//create head of an linked list
	n = new node;
	n->e_Ship = temp;
	n->prev = NULL;
	head = n;
	tail = n;

	//create first row -1 cuz thats the head
	//row is 10 units total
	//create privates (enemy Ships)
	for (int i = 1; i < 10; i++){
		position = glm::vec2(enemyFormStart.x + enemyWidth*i, enemyFormStart.y);
		temp = new Private(imgLib, screen, position, velocity, width, height);

		n = new node;
		n->e_Ship = temp;
		n->prev = tail;
		tail->next = n;
		tail = n;
	}

	//create 2nd row
	//row is 10 units
	//create privates (enemy Ships) (enemy Ships)
	for (int i = 0; i < 10; i++){
		position = glm::vec2(enemyFormStart.x + enemyWidth*i, enemyFormStart.y - enemyHeight);
		temp = new Private(imgLib, screen, position, velocity, width, height);

		n = new node;
		n->e_Ship = temp;
		n->prev = tail;
		tail->next = n;
		tail = n;
	}

	//create 3rd row
	//row is 10 units
	//create privates (enemy Ships)
	for (int i = 0; i < 10; i++){
		position = glm::vec2(enemyFormStart.x + enemyWidth*i, enemyFormStart.y - enemyHeight * 2);
		temp = new Private(imgLib, screen, position, velocity, width, height);

		n = new node;
		n->e_Ship = temp;
		n->prev = tail;
		tail->next = n;
		tail = n;
		tail->next = NULL;
	}

	//create 4th row
	//row is 8 units
	//create corporals
	for (int i = 0; i < 8; i++){
		position = glm::vec2(enemyWidth + enemyFormStart.x + enemyWidth*i, enemyFormStart.y - enemyHeight * 3);
		temp = new Corporal(imgLib, screen, position, velocity, width, height);

		n = new node;
		n->e_Ship = temp;
		n->prev = tail;
		tail->next = n;
		tail = n;
	}
	//create 5th row
	//row is 6 units
	//create sergeants
	for (int i = 0; i < 6; i++){
		position = glm::vec2(enemyWidth * 2 + enemyFormStart.x + enemyWidth*i, enemyFormStart.y - enemyHeight * 4);
		temp = new Sergeant(imgLib, screen, position, velocity, width, height);
		temp->isSergeant = true;

		n = new node;
		n->e_Ship = temp;
		n->prev = tail;
		tail->next = n;
		tail = n;
	}

	//create 6th row
	// row is 2 units 1 is tail
	// create lieutenants
	position = glm::vec2(enemyWidth * 3 + enemyFormStart.x, enemyFormStart.y - enemyHeight * 5);
	temp = new Lieutenant(imgLib, screen, position, velocity, width, height);
	temp->isLieutenant = true;
	n = new node;
	n->e_Ship = temp;
	n->prev = tail;
	tail->next = n;
	tail = n;

	//create tail
	position = glm::vec2(enemyWidth * 3 + enemyFormStart.x + enemyWidth * 3, enemyFormStart.y - enemyHeight * 5);
	temp = new Lieutenant(imgLib, screen, position, velocity, width, height);
	temp->isLieutenant = true;

	n = new node;
	n->e_Ship = temp;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

void EnemyHandler::Update(Bullet* p_Bullet)
{
	node* temp = head;
	node* temp1 = NULL;
	bool hitEdge = false;

	//go trough the linked list

	while (temp != NULL)
	{
		//update ship - give players bullet to check collision 
		temp->e_Ship->Update(p_Bullet);

		// if ship is goign down use rand to shoot yes or no
		if (temp->e_Ship->state == 3)
		{
			int  j = rand() % 101;

			if (j == 2){
				EnemyShoot(temp->e_Ship);
			}
		}

		//check if ship is hit by player
		if (temp->e_Ship->isHit)
		{
			temp1 = temp;
		}

		// generate an random number between certain range for enemy to set off
		// the range of rand wil decrese per level
		int b = 3000 - 1000 * levels;
		int i = rand() % (b + 1000);

		//int used for lieutenant formation
		// d wil be changed if lieutenant pos.x > scrwidth /2
		// if  sergent pos > d sereant charges aswell 
		// this is needed otherwise they might go arc the other way
		int d = 0;

		//go charge
		// is i 1?  is the ship not charging? is  the position within boundries *  otherwise they go out of screen
		if (i == 1  &&
			!temp->e_Ship->isCharging &&
			temp->e_Ship->position.x > 0 + temp->e_Ship->r * 2 &&
			temp->e_Ship->position.x < SCRWIDTH - temp->e_Ship->width - temp->e_Ship->r * 2)
		{
			//is ship an lieutenant
			if (temp->e_Ship->isLieutenant)
			{
				temp->e_Ship->Charge(p_Ship->GetMiddleVec());

				//is thelieutenant  pos past the half of scrwidth?
				if (temp->e_Ship->position.x > SCRWIDTH / 2)
				{
					d = SCRWIDTH / 2;
				}
				

				//search sergeants for charge
				node* temp2 = temp;
				
				while (temp2->e_Ship->isLieutenant || temp2->e_Ship->isSergeant)
				{
					if (temp2->e_Ship->isSergeant)
					{

						//check if sergeant lays below within certain x range and past d
						if (temp2->e_Ship->position.x >= temp->e_Ship->position.x - 50 &&
							temp2->e_Ship->position.x <= temp->e_Ship->position.x + 50 &&
							temp2->e_Ship->position.x > d)
						{
							float e = temp->e_Ship->position.x - temp2->e_Ship->position.x;
							temp2->e_Ship->Charge(glm::vec2(p_Ship->GetMiddleVec().x - e, p_Ship->GetMiddleVec().y));
						}
					}
					temp2 = temp2->prev;
				}
			}
			//if not lieutenant and sergeant
			else if (!temp->e_Ship->isSergeant)
			{
				temp->e_Ship->Charge(p_Ship->GetMiddleVec());
			}
			//if sergeant and no lieutenants alive
			else if (temp->e_Ship->isSergeant && lieutenantsAlive <= 0)
			{
				temp->e_Ship->Charge(p_Ship->GetMiddleVec());
			}
		}

		//check if an ship has hit the edge while not charging * failsafe ^^
		if (temp->e_Ship->hitEdge && !temp->e_Ship->isCharging)
		{
			hitEdge = true;
		}
		temp = temp->next;
	}

	//if an enemy has been hit go delete it
	if (temp1 != NULL && temp1->e_Ship->isHit)
	{
		DeleteEnemy(temp1);
	}
	// an ship had hit the edge turn al the ships
	if (hitEdge)
	{
		temp = head;
		while (temp != NULL)
		{
			temp->e_Ship->TurnAround();
			temp = temp->next;
		}
	}

	temp = head;
	//redraw charging chips to get them infornt of formation
	while (temp != NULL)
	{
		if (temp->e_Ship->isCharging)
		{
			temp->e_Ship->Draw();
		}
		temp = temp->next;
	}

	// handle the enemy bullets
	handleBullets();
}

void EnemyHandler::handleBullets()
{

	Bullets* delBullet = NULL;
	bool hitEdge = false;

	// go trough bullet list
	if (!noBulletsAlive)
	{
		Bullets* tempBullet = b_Head;
		tempBullet = b_Head;
		while (tempBullet != NULL)
		{	
			//has the bullet hit the player?
			CheckHitPlayer(tempBullet);

			tempBullet->bullet->Update();
			tempBullet->bullet->Draw();

			//has the bullet hit the edge?
			if (tempBullet->bullet->hitEdge)
			{
				delBullet = tempBullet;
			}

			tempBullet = tempBullet->next;

			//del the bullet if != null
			if (delBullet != NULL)
			{
				deleteEnemyBullets(delBullet);
				delBullet = NULL;
			}
		}
	}
}

void EnemyHandler::CheckHitPlayer(Bullets* tempBullet)
{
	//player is hit
	if (tempBullet->bullet->PlayerHit(p_Ship))
	{
		p_Ship->isHit = true;

		// place bullet out of screen to del it
		tempBullet->bullet->position.y = -100;
	}
}

//delete the bullet from linked list and memory
void EnemyHandler::deleteEnemyBullets(Bullets* b)
{
	//is b the last object alive?
	if (b->next == NULL && b->prev == NULL)
	{
		noBulletsAlive = true;
	}
	// is b head?
	else if (b->prev == NULL)
	{
		b->next->prev = NULL;
		b_Head = b->next;
	}
	//is b tail?
	else if (b->next == NULL)
	{
		b->prev->next = NULL;
		b_Tail = b->prev;
	}
	else
	{
		b->prev->next = b->next;
		b->next->prev = b->prev;
	}

	delete b;
}

//enemy do shoot
void EnemyHandler::EnemyShoot(EnemyShip* enemy)
{
	//get size of bullet
	int width = imgLib->bullet->GetWidth();
	int height = imgLib->bullet->GetHeight();

	//set speed of bulelt
	glm::vec2 velocity = glm::vec2(0.0f, 1.0f * bulletSpeed);

	//set output position of the bullet in front of  the ship
	glm::vec2 position = enemy->GetMiddleVec();
	position.y += enemy->height;
	
	//create bullet and ad to list
	Bullet* tempBullet = new Bullet(imgLib, screen, position, velocity, width, height);

	// if theres isnt an bullet create head
	if (noBulletsAlive)
	{
		b = new Bullets;
		b->bullet = tempBullet;
		b->prev = NULL;
		b->next = NULL;
		b_Head = b;
		b_Tail = b;

		noBulletsAlive = false;
	}
	//else ad to list
	else
	{
		b = new Bullets;
		b->bullet = tempBullet;
		b->prev = b_Tail;
		b_Tail->next = b;
		b_Tail = b;
		b_Tail->next = NULL;
	}
}

//delete the enemy hit
void EnemyHandler::DeleteEnemy(node* n)
{
	//draw dead enamation;
	n->e_Ship->DrawDead();

	//print the score of the enemy on position
	char points[50];
	int a = n->e_Ship->points;
	sprintf(points, "%d", a);
	screen->Print(points, (int)n->e_Ship->position.x, (int)n->e_Ship->position.y, 0xffffff);

	//if lieutenant is hit decrease the counter
	if (n->e_Ship->isLieutenant)
	{
		lieutenantsAlive--;
	}

	//delete
	//is N last?
	if (n->next == NULL && n->prev == NULL)
	{
		CreateFormation();
		levels++;
	}
	//n is head
	else if (n->prev == NULL)
	{
		n->next->prev = NULL;
		head = n->next;
	}
	//n is tail
	else if (n->next == NULL)
	{
		n->prev->next = NULL;
		tail = n->prev;
	}
	else
	{
		n->prev->next = n->next;
		n->next->prev = n->prev;
	}

	//update score
	score += n->e_Ship->points;

	//delete object
	delete n;
}