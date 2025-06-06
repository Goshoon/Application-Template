#pragma once
#include "application.h"

class Entity
{
public:
	Entity();
	Entity(int x, int y);

	unsigned short frameIndex, xOffset, yOffset;
	bool animated;

	SDL_Texture* sprite;
	SDL_Rect position; // Position on virtual enviroment

	bool CheckCollision(const Entity& other) const 
	{
  		return SDL_HasIntersection(&position, &other.position);
	}


	void Update();
	void Draw();
private:
	SDL_Rect frame; // Animation Frame
  Application& app = Application::GetInstance();
};
