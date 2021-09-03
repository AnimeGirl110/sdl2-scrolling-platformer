#include <algorithm>
#include "Config.hpp"
#include <stdio.h>
#include "World.hpp"

using namespace Game;

World::World(float dimX, float dimY)
    : dim(dimX, dimY),
      // dimMin(std::min(dim.x, dim.y)),
      // dimPrior(dim.x, dim.y),
      max(0.5 * dimX, 0.5 * dimY),
      min(-max.x, -max.y)
{
  printf("    World::World()\n");
  // Current version of World has nothing further to do during construction.
}

World::~World()
{
  printf("    World::~World()\n");
  // Current version of World has nothing further to do during destruction.
}

// void World::Resize()
// {
//   dim.x = world;
//   dim.y = dimY;
//   max.x = 0.5 * dimX;
//   max.y = 0.5 * dimY;
//   min.x = -max.x;
//   min.y = -max.y;
//   dimMin = std::min(dim.x, dim.y);
// }

// void World::Resize(float dimX, float dimY)
// {
//   printf("    World::Resize()\n");
//   dimPrior.x = dim.x;
//   dimPrior.y = dim.y;
//   dimMinPrior = dimMin;
//   dim.x = dimX;
//   dim.y = dimY;
//   max.x = 0.5 * dimX;
//   max.y = 0.5 * dimY;
//   min.x = -max.x;
//   min.y = -max.y;
//   dimMin = std::min(dim.x, dim.y);
// }

// void World::Resize(float maxX, float maxY, float minX, float minY)
// {
//   dim.x = maxX - minX;
//   dim.y = maxY - minY;
//   max.x = maxX;
//   max.y = maxY;
//   min.x = minX;
//   min.y = minY;
//   dimMin = std::min(dim.x, dim.y);
// }
