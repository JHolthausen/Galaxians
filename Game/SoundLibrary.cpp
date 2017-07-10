#include "SoundLibrary.h"

SoundLibrary::SoundLibrary()
{
}

SoundLibrary::~SoundLibrary()
{
}

void SoundLibrary::PlayDestroy()
{
	PlaySound(TEXT("assets/Mario Coin"), NULL, SND_ASYNC);
}
void SoundLibrary::PlayBackground()
{
	PlaySound(TEXT("assets/Dropkick"), NULL, SND_LOOP);
}
void SoundLibrary::PlayShoot()
{
	PlaySound(TEXT("assets/LaserShot"), NULL, SND_SYNC);
}