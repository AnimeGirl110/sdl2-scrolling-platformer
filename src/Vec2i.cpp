#include <stdio.h>
#include "Vec2i.hpp"

// TYM SAYS:  Vec2i.cpp looks good.

using namespace Game;

Vec2i::Vec2i(int x, int y)
    : x(x), y(y)
{
  printf("      Vec2i::Vec2i(%d, %d)\n", x, y);
}
