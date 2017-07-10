#pragma once

// Include GameObjects.
#include "EnemyShip.h"
#include "Private.h"
#include "Corporal.h"
#include "Sergeant.h"
#include "Lieutenant.h"
#include "Bullet.h"
#include "PlayerShip.h"

// Include Library's 
#include "ImageLibrary.h"
#include "SoundLibrary.h"

// Include others.
#include "game.h"
#include <thread>       

namespace Tmpl8{
	class EnemyHandler
	{
		// Create node struct with EnemyShip for Double Linked list.
		struct node
		{
			EnemyShip* e_Ship;
			node* next;
			node* prev;
		};

		// Create node struct with EnemyShip for Double Linked list.
		struct Bullets
		{
			Bullet* bullet;
			Bullets* next;
			Bullets* prev;
		};

	public:

		// Default Constructor & Destructor.
		EnemyHandler();
		~EnemyHandler();

		// Override constructor.
		EnemyHandler(ImageLibrary* imgLib, Surface* screen);
		
		// Custom functions.
		void CreateFormation();
		void Update(Bullet* p_Bullet);
		void DeleteEnemy(node* n);
		void EnemyShoot(EnemyShip* enemy);
		void handleBullets();
		void deleteEnemyBullets(Bullets* b);
		void CheckHitPlayer(Bullets* tempBullet);

		// Declare Variable's.

		// Variables used for double linked list.
		node* n;
		node* head;
		node* tail;

		Bullets* b;
		Bullets* b_Head = NULL;
		Bullets* b_Tail;

		// Variables used for creating formation.
		glm::vec2 enemyFormStart;
		int enemyWidth = 40;	//	this is the default width for every enemy.
		int enemyHeight = 40;	//	this is the default height for every enemy.

		// Variables to pass to the gui.
		int score = 0;
		int levels = 1;

		// Other
		ImageLibrary* imgLib;
		Surface* screen;
		float bulletSpeed = 6;			// Speed of the bullets.
		PlayerShip* p_Ship = NULL;		// Pointer wil get declared in game class
		bool noBulletsAlive = true;
		int lieutenantsAlive = 2;
	};
}