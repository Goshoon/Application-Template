#pragma once
#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "entity.h"

class Quadtree {
    static const int MAX_ENTITIES = 4;
    static const int MAX_LEVELS = 5;

    int level;
    SDL_Rect bounds;
    std::vector<Entity*> entities;
    std::vector<std::unique_ptr<Quadtree>> nodes;
public:
    Quadtree(int level, SDL_Rect bounds);
    void Clear();
    void Split();
    int GetIndex(const SDL_Rect& rect) const;
    void Insert(Entity* entity);
    void Retrieve(std::vector<Entity*>& returnEntities, const SDL_Rect& area);
    void Draw(SDL_Renderer* renderer) const;
};
