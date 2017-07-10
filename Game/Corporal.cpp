#include "Corporal.h"


// Default constructor.
Corporal::Corporal()
{
}

// Default destructor.
Corporal::~Corporal()
{
}

// Override parent Draw().
void Corporal::Draw()
{
	// Draw the corporal image. 
	imgLib->i_Corporal->CopyTo(screen, (int)position.x, (int)position.y);
}

// Override Parent Drawdead().
void Corporal::DrawDead()
{
	// Draw the corporaldead image.
	imgLib->i_CorporalDead->CopyTo(screen, (int)position.x, (int)position.y);
}