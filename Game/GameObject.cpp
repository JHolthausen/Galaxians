#include "GameObject.h"

using namespace Tmpl8;				// to use template classes
using namespace glm;				// to use glm vector stuff

GameObject::GameObject(ImageLibrary* imgLib, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int height)
{

	//set the objects
	this->imgLib = imgLib;
	this->screen = screen;
	this->position = position;
	this->velocity = velocity;
	this->width = width;
	this->height = height;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	//update position
	position += velocity;

	//check if the edge is been hit
	if (position.y < 0 ||
		position.y > SCRHEIGHT ||
		position.x < 0 ||
		position.x > SCRWIDTH - width
		)
	{
		hitEdge = true;
	}
	else
	{
		hitEdge = false;
	}
}

void GameObject::Draw()
{
}

void GameObject::Create()
{
}

//return an vector wich is the middel of the object
glm::vec2 GameObject::GetMiddleVec()
{
	return glm::vec2(position.x + width / 2, position.y + height / 2);
}

//get the radius of the object, width/2 is used because width = height
float GameObject::GetRadius()
{
	return (float)width / 2;
}