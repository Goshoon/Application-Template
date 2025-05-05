#include "quadtree.h"

Quadtree::Quadtree(int level, SDL_Rect bounds)
    : level(level), bounds(bounds) {}

void Quadtree::Clear()
{
    entities.clear();
    for (auto& node : nodes)
    {
        if (node) node->Clear();
    }
    nodes.clear();
}

void Quadtree::Split()
{
    int subWidth = bounds.w / 2;
    int subHeight = bounds.h / 2;
    int x = bounds.x;
    int y = bounds.y;

    nodes.emplace_back(std::make_unique<Quadtree>(level + 1, SDL_Rect{x + subWidth, y, subWidth, subHeight}));
    nodes.emplace_back(std::make_unique<Quadtree>(level + 1, SDL_Rect{x, y, subWidth, subHeight}));
    nodes.emplace_back(std::make_unique<Quadtree>(level + 1, SDL_Rect{x, y + subHeight, subWidth, subHeight}));
    nodes.emplace_back(std::make_unique<Quadtree>(level + 1, SDL_Rect{x + subWidth, y + subHeight, subWidth, subHeight}));
}

int Quadtree::GetIndex(const SDL_Rect& rect) const
{
    int verticalMidpoint = bounds.x + bounds.w / 2;
    int horizontalMidpoint = bounds.y + bounds.h / 2;

    bool top = rect.y + rect.h < horizontalMidpoint;
    bool bottom = rect.y > horizontalMidpoint;
    bool left = rect.x + rect.w < verticalMidpoint;
    bool right = rect.x > verticalMidpoint;

    if (top && right) return 0;
    if (top && left) return 1;
    if (bottom && left) return 2;
    if (bottom && right) return 3;

    return -1;  // doesn't fit neatly into a quadrant
}

void Quadtree::Insert(Entity* entity) 
{
    if (!nodes.empty())
    {
        int index = GetIndex(entity->position);
        if (index != -1)
        {
            nodes[index]->Insert(entity);
            return;
        }
    }

    entities.push_back(entity);

    if (entities.size() > MAX_ENTITIES && level < MAX_LEVELS)
    {
        if (nodes.empty()) Split();

        auto it = entities.begin();
        while (it != entities.end())
        {
            int index = GetIndex((*it)->position);
            if (index != -1)
            {
                nodes[index]->Insert(*it);
                it = entities.erase(it);
            } 
            else
            {
                ++it;
            }
        }
    }
}

void Quadtree::Retrieve(std::vector<Entity*>& returnEntities, const SDL_Rect& area) 
{
    int index = GetIndex(area);
    if (index != -1 && !nodes.empty()) {
        nodes[index]->Retrieve(returnEntities, area);
    }

    returnEntities.insert(returnEntities.end(), entities.begin(), entities.end());
}

void Quadtree::Draw(SDL_Renderer* renderer) const
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red borders
    SDL_RenderDrawRect(renderer, &bounds);

    for (const auto& node : nodes) 
    {
        if (node) node->Draw(renderer);
    }
}
