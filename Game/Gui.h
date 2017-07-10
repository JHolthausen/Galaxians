#pragma once

#include <string>
#include <iostream>
#include <stdio.h>

#include <fstream>

#include "template.h"
#include "surface.h"
#include "game.h"
#include "ImageLibrary.h"

using namespace Tmpl8;				// to use template classes
using namespace glm;				// to use glm vector stuff
using namespace std;

namespace Tmpl8 {
	class Gui
	{
	public:
		Gui(){};
		Gui(ImageLibrary* imgLib, Surface* screen);
		~Gui();
		void Draw();
		void Update(int score, int levels);
		void DoStart();
		void DoEndGame();
		void SaveHighScore();
		void HandleHighScore();

		int oldHighScore;
		int highScore = 0;
		ImageLibrary* imgLib;
		int lives = 3, score = 0, levels;
		std::string lifeString, scoreString;
		Surface* screen;

		int i = 0;
		bool startGame = false;
	};
};