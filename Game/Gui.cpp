#include "Gui.h"

Gui::Gui(ImageLibrary* imgLib, Surface* screen)
{
	this->imgLib = imgLib;
	this->screen = screen;


	//set the highscore
	string line;

	//Opens file
	ifstream b_file("assets/HighScore.txt");
	//Reads one string from the file
	getline(b_file, line);
	//string to int
	oldHighScore = std::stoi(line);
	//close file stream
	b_file.close();
}

Gui::~Gui()
{
}

void Gui::Update(int score, int levels)
{
	this->score = score;
	this->levels = levels;
	HandleHighScore();
	Draw();
}

void Gui::HandleHighScore()
{
	//if the highscore is past current sccore i highscore
	if (oldHighScore < score)
	{
		highScore = score;
	}
	else
	{
		highScore = oldHighScore;
	}
}

void Gui::SaveHighScore()
{
	//open the file for writing
	ofstream a_file("assets/HighScore.txt");
	// save the highscore in file // overwrites
	a_file << highScore << endl;
	// Close the file 
	a_file.close();
}

void Gui::DoStart()
{
	screen->Print("WE ARE GALAXIANS !", SCRWIDTH / 2 - 50, 300, 0xffffff);
	screen->Print("Mission: DESTROY ALIENS", SCRWIDTH / 2 - 70, 320, 0xffffff);
	screen->Print("- SCORE ADVANCE TABLE - ", SCRWIDTH / 2 - 70, 370, 0xffffff);
	screen->Print("CONVOY	CHARGER", SCRWIDTH / 2 - 10, 390, 0xffffff);
	screen->Print("YELLOW", SCRWIDTH / 2 - 70, 410, 0xffffff);	screen->Print("60", SCRWIDTH / 2, 410, 0xffffff); screen->Print("120", SCRWIDTH / 2 + 30, 410, 0xffffff);
	screen->Print("RED", SCRWIDTH / 2 - 70, 430, 0xffffff);		screen->Print("50", SCRWIDTH / 2, 430, 0xffffff); screen->Print("100", SCRWIDTH / 2 + 30, 430, 0xffffff);
	screen->Print("PURPLE", SCRWIDTH / 2 - 70, 450, 0xffffff);	screen->Print("40", SCRWIDTH / 2, 450, 0xffffff); screen->Print("80", SCRWIDTH / 2 + 30, 450, 0xffffff);
	screen->Print("BLUE", SCRWIDTH / 2 - 70, 470, 0xffffff);	screen->Print("30", SCRWIDTH / 2, 470, 0xffffff); screen->Print("60", SCRWIDTH / 2 + 30, 470, 0xffffff);

	screen->Print("Controls", SCRWIDTH / 2 - 20, 500, 0xffffff);
	screen->Print("Move", SCRWIDTH / 2 - 70, 520, 0xffffff);	screen->Print("Left right", SCRWIDTH / 2, 520, 0xffffff);
	screen->Print("Shoot", SCRWIDTH / 2 - 70, 540, 0xffffff);	screen->Print("Up", SCRWIDTH / 2, 540, 0xffffff);
	screen->Print("Pauze", SCRWIDTH / 2 - 70, 560, 0xffffff);	screen->Print("p", SCRWIDTH / 2, 560, 0xffffff);


	//use int i to flicker the space text
	if (i < 20)
	{
		screen->Print("PRESS SPACE ", SCRWIDTH / 2 - 40, 600, 0xffffff);
	}
	else if (i >= 20 && i < 30)
	{
	}
	else{
		i = 0;
	}
	i++;

	//is spaced pressed?
	if (GetAsyncKeyState(32)){
		startGame = true;
	}
}

void Gui::DoEndGame()
{
	screen->Print("Game Over", SCRWIDTH / 2 -10, 300, 0xffffff);
	char points[50];

	int n, a = score;
	n = sprintf(points, "%d", a);
	screen->Print(points, SCRWIDTH / 2, 310, 0xffffff);
	SaveHighScore();
}
void Gui::Draw()
{
	//print highscore
	screen->Print("High Score", SCRWIDTH / 4, 2, 0xffffff);

	char c_highScore[50];

	int n, a = highScore;
	n = sprintf(c_highScore, "%d", a);
	screen->Print(c_highScore, SCRWIDTH / 4, 10, 0xffffff);

	//score text
	screen->Print("Score", SCRWIDTH / 2, 2, 0xffffff);

	//score int
	char points[50];

	a = score;
	n = sprintf(points, "%d", a);
	screen->Print(points, SCRWIDTH / 2, 10, 0xffffff);

	//player lives presented in sprites;
	for (int i = 0; i < lives; i++)
	{
		imgLib->playerShip->CopyTo(screen, i * imgLib->ball->GetWidth(), SCRHEIGHT - imgLib->ball->GetHeight());
	}

	//Current lvl presented in sprites
	for (int i = 0; i < levels; i++)
	{
		imgLib->flag->CopyTo(screen, SCRWIDTH - i* imgLib->flag->GetWidth() - 20, SCRHEIGHT - imgLib->flag->GetHeight() - 20);
		//guiLayer->Print("10", SCRWIDTH - 40, SCRHEIGHT - 40, 0xffffff);
	}
}