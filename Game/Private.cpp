#include "Private.h"

//default constructor
Private::Private()
{
}

//default constructor
Private::~Private()
{
}

//override parent
void Private::Draw()
{
	imgLib->i_Private->CopyTo(screen, (int)position.x, (int)position.y);
}

//override parent
void Private::DrawDead()
{
	imgLib->i_PrivateDead->CopyTo(screen, (int)position.x, (int)position.y);
}