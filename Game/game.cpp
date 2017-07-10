#include "game.h"

//include the library's here because game.h is used in mutiple cpp files and there's only 1 instance of game

#include "PlayerHandler.h"
#include "EnemyHandler.h"
#include "Gui.h"
#include "Starfield.h"
#include "SoundLibrary.h"

#include <iostream>       // std::cout
#include <thread>         // std::thread

using namespace Tmpl8;				// to use template classes
using namespace glm;				// to use glm vector stuff

//declare variables
PlayerHandler* ph;
EnemyHandler* eh;
Gui* gui;
StarField* starField;
SoundLibrary* soundLib;

std::thread* first;  


//--------------------------
// Threads
//--------------------------
void BackGroundMusic()
{
	soundLib->PlayBackground();
}


// -----------------------------------------------------------
// Initialize the game
// -----------------------------------------------------------

// game initialization code goes here;
// will be executed once when app starts


void Game::Init()
{
	//declare variables
	ImageLibrary* imgLib = new ImageLibrary;
	ph = new PlayerHandler(imgLib, screen);
	eh = new EnemyHandler(imgLib, screen);
	gui = new Gui(imgLib, screen);
	starField = new StarField(screen);
	soundLib = new SoundLibrary();

	// start the tread once, music keeps looping
	first = new std::thread(BackGroundMusic); 
}

// -----------------------------------------------------------
// Main game tick function
// -----------------------------------------------------------

void Game::Tick(float _DT)
{
	// clear the canvas
	screen->Clear(0);
	switch (state)
	{
		//intro
	case 0:

		starField->Update();
		gui->DoStart();

		if (gui->startGame)
		{
			state = 1;
		}

		break;

		//the game
	case 1:
		starField->Update();

		eh->p_Ship = ph->p_Ship;

		ph->Update();
		eh->Update(ph->bullet);
		gui->Update(eh->score, eh->levels);
		gui->lives = ph->lives;

		//pauze the game, p key
		if (GetAsyncKeyState(80))
		{
			Sleep(100);
			while (!GetAsyncKeyState(80))
			{
			}
			Sleep(100);
		}



		if (ph->lives == 0)
		{
			state = 2;
		}
		break;
		//endgame
	case 2:

		gui->DoEndGame();
		break;
	}
}
