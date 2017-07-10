#include "ImageLibrary.h"

ImageLibrary::ImageLibrary()
{
	ball = new Surface("assets/ball.png");

	playerShip = new Surface("assets/playerShip.png");
	bullet = new Surface("assets/bullet.png");

	//init enemy's
	i_Sergeant = new Surface("assets/redShip.png");
	i_Private = new Surface("assets/blueShip.png");
	i_Corporal = new Surface("assets/purpleShip.png");
	i_Lieutenant = new Surface("assets/yellowShip.png");

	i_CorporalDead = new Surface("assets/purpleDead1.png");
	i_PrivateDead = new Surface("assets/blueDead1.png");
	i_SergeantDead = new Surface("assets/redDead1.png");
	i_LieutenantDead = new Surface("assets/yellowDead1.png");

	i_playerDead = new Surface("assets/playerDead.png");

	//init gui assets
	flag = new Surface("assets/flag.png");
}

ImageLibrary::~ImageLibrary()
{
}