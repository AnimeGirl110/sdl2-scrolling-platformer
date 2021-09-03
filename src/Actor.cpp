#include <algorithm>
#include "Actor.hpp"
#include <stdio.h>

using namespace Game;

// Static variables must be initialized in cpp code outside of hpp declaration.
std::vector<Actor *> Actor::actors;
Model *Actor::model = nullptr;
World *Actor::world = nullptr;

void Actor::SetModel(Model *model)
{
  printf("    Actor::SetModel()\n");
  Actor::model = model;
}

void Actor::SetWorld(World *world)
{
  printf("    Actor::SetWorld()\n");
  Actor::world = world;
}

Actor::Actor(float posX, float posY, float ori, float dimX, float dimY)
    : dim(dimX, dimY),
      // dimMax(std::max(dimX, dimY)),
      ori(ori),
      pos(posX, posY)
{
  printf("    Actor::Actor()\n");
  // Add the new actor to the end of the static collection of actors.
  actors.emplace_back(this);
}

// Deletion of an actor triggers this destructor, so don't do "delete" op here.
Actor::~Actor()
{
  printf("    Actor::~Actor()\n");
  auto it = std::find(actors.begin(), actors.end(), this);
  if (it != actors.end())
  {
    // This quick deletion trick works so long as the vector isn't "ordered."
    std::iter_swap(it, actors.end() - 1);
    actors.pop_back();
  }
}

void Actor::ChangeDimX(float dx)
{
  dim.x += dx;
  // dimMax = std::max(dim.x, dim.y);
}

void Actor::ChangeDimY(float dy)
{
  dim.y += dy;
  // dimMax = std::max(dim.x, dim.y);
}

void Actor::SetDim(float x, float y)
{
  dim.x = x;
  dim.y = y;
  // dimMax = std::max(dim.x, dim.y);
}

void Actor::SetDimX(float x)
{
  dim.x = x;
  // dimMax = std::max(dim.x, dim.y);
}

void Actor::SetDimY(float y)
{
  dim.y = y;
  // dimMax = std::max(dim.x, dim.y);
}

void Actor::SetPos(float x, float y)
{
  pos.x = x;
  pos.y = y;
}
