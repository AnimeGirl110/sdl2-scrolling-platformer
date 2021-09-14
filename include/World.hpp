#pragma once
#include "Vec2f.hpp"

// TYM SAYS: World.hpp - Didn't make any changes, but needs some clean-up.

namespace Game
{
  // World contains information about the game's boundaries.
  class World
  {
  public:
    // Constructs a new world object.
    World(float dimX, float dimY);
    // Destructs a world object.
    ~World();

    // Gets the world's minimum x or y dimension.
    // float GetDimMin() { return dimMin; }
    // Gets the world's prior minimum x or y dimension (before last resizing).
    // float GetDimMinPrior() { return dimMinPrior; }
    // Gets the world's x-dimension.
    float GetDimX() { return dim.x; }
    // Gets the world's prior x-dimension (before last resizing).
    // float GetDimXPrior() { return dimPrior.x; }
    // Gets the world's prior x-dimension (before last resizing).
    // float GetDimYPrior() { return dimPrior.y; }
    // Gets the world's y-dimension.
    float GetDimY() { return dim.y; }
    // Gets the world's maximum x-position.
    float GetMaxX() { return max.x; }
    // Gets the world's maximum y-position.
    float GetMaxY() { return max.y; }
    // Gets the world's minimum x-position.
    float GetMinX() { return min.x; }
    // Gets the world's minimum y-position.
    float GetMinY() { return min.y; }

    //
    // void Resize();
    // Resizes the world with assumption of balanced min and max coordinates.
    // void Resize(float dimX, float dimY);
    // Resizes the world with explicit min and max coordinates.
    // void Resize(float maxX, float maxY, float minX, float minY);

  private:
    // 2D vector comprising the world's dimensions.
    Vec2f dim;
    // Magnitude of minimum x or y dimension.
    // float dimMin;
    // Magnitude of minimum x or y dimension before last resizing event.
    // float dimMinPrior;
    // 2D vector comprising the world's dimensions before last resizing event.
    // Vec2f dimPrior;
    // 2D vector comprising the world's maximum x- and y-positions.
    Vec2f max;
    // 2D vector comprising the world's minimum x- and y-positions.
    Vec2f min;
  };
}
