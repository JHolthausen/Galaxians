#include "Lieutenant.h"

//default constructor
Lieutenant::Lieutenant()
{
}

//default destructor
Lieutenant::~Lieutenant()
{
}

//override parent draw
void Lieutenant::Draw()
{
	imgLib->i_Lieutenant->CopyTo(screen, (int)position.x, (int) position.y);
}

//override parent drawdead
void Lieutenant::DrawDead()
{
	imgLib->i_LieutenantDead->CopyTo(screen, (int)position.x, (int) position.y);
}