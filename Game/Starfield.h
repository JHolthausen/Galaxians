#pragma once

#include "template.h"
#include "surface.h"
#include "game.h"
#include "Star.h"

namespace Tmpl8{
	struct noded
	{
		Star* star;
		noded* next;
		noded* prev;
	};

	class StarField
	{
	public:

		StarField(Surface* scrn);
		~StarField();

		void Update();
		void CreateStars();
		void Draw();
		//void DeleteStar(noded* n);

		//Linked list
		noded* head;
		noded* tail;
		noded* n;

		int starAmount = 300;
		Surface* screen;
		glm::vec2 position[300];
	};
}