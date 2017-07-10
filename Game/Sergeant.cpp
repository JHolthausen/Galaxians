#include "Sergeant.h"

//default constructor
Sergeant::Sergeant()
{
}

//default destructor
Sergeant::~Sergeant()
{
}

//override parent
void Sergeant::Draw()
{
	imgLib->i_Sergeant->CopyTo(screen, (int)position.x, (int)position.y);
}

//override parent
void Sergeant::DrawDead()
{
	imgLib->i_SergeantDead->CopyTo(screen, (int)position.x, (int)position.y);
}