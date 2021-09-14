#pragma once

// TYM SAYS:  Vec2i.hpp looks good.

namespace Game
{
  // Structure comprising a 2D integer vector.
  struct Vec2i
  {
    // Constructs a 2D integer vector, with default values (0, 0).
    Vec2i(int x = 0, int y = 0);

    // X-component.
    int x;
    // Y-component.
    int y;
  };
}
