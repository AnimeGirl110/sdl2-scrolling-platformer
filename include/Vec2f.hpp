#pragma once

namespace Game
{
  // Structure comprising a 2D floating-point vector.
  struct Vec2f
  {
    // Constructs a 2D floating-point vector, with default values (0, 0)
    Vec2f(float x = 0, float y = 0);

    // X-component.
    float x;
    // Y-component.
    float y;
  };
}
