#include <stdio.h>
#include "Vec2f.hpp"

// TYM SAYS:  Vec2f.cpp looks good.

using namespace Game;

Vec2f::Vec2f(float x, float y)
    : x(x), y(y)
{
  printf("      Vec2f::Vec2f(%.1f, %.1f)\n", x, y);
}
