#pragma once

#include "template.h"
#include "surface.h"
#include "ImageLibrary.h"
#include "game.h"

namespace Tmpl8{
	class GameObject
	{
	public:

		//default constructor/destructor
		GameObject(){};
		~GameObject();

		//override constructor
		GameObject(ImageLibrary* imgLib, Surface* screen, glm::vec2 position, glm::vec2 velocity, int width, int heigth);
		
		//functions that wil be overriden
		virtual void Create();
		virtual void Draw();
		virtual void Update();

		//custom functions
		glm::vec2 GetMiddleVec();
		float GetRadius();

		//variables wich get declared trough constructor
		glm::vec2 position, velocity;
		int width, height;
		ImageLibrary* imgLib;
		Surface* screen;
		bool hitEdge = false;
	};
}