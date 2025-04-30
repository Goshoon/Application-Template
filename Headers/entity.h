#pragma once
#include <memory>
#include "application.h"
using std::unique_ptr;

extern unique_ptr<Application> app;

class Entity
{
public:
	Entity();
	Entity(int x, int y);

	unsigned short frame, xOffset, yOffset;
	bool animated;

	SDL_Texture* sprite;
	SDL_Rect position; // Position on game screen

	void Update();
	void Draw();
private:
	SDL_Rect frame; // Animation Frame
};
