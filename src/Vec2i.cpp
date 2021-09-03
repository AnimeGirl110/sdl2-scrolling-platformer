#include <stdio.h>
#include "Vec2i.hpp"

using namespace Game;

Vec2i::Vec2i(int x, int y)
    : x(x), y(y)
{
  printf("      Vec2i::Vec2i(%d, %d)\n", x, y);
}
