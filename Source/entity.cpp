#include "entity.h"

Entity::Entity()
{}

Entity::Entity(int x, int y)
{
	SDL_Point _spriteDimentions;
	SDL_QueryTexture(sprite, NULL, NULL, &_spriteDimentions.x, &_spriteDimentions.y);

  frameIndex = 0;
  frame.x = 0;
	frame.y = 0;
	frame.w = _spriteDimentions.x;
	frame.h = _spriteDimentions.y;

	position.x = x;
	position.y = y;
	position.w = _spriteDimentions.x;
	position.h = _spriteDimentions.y;
}

void Entity::Update()
{}

void Entity::Draw()
{
	SDL_RenderCopy(app.renderer, sprite, NULL, &position);
}

bool Entity::CheckCollision(const Entity& other) const 
{
  return SDL_HasIntersection(&position, &other.position);
}
