#pragma once
#include "Actor.hpp"
#include "ViewAble.hpp"

namespace Game
{
  class Background
      : public Actor,
        public ViewAble
  {
  public:
    // Constructs a background
    Background();
    // Destructs a background
    ~Background();

    // Overrides Actor's Resize() method.
    // void Resize() override;
  };
}
