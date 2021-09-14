#pragma once
#include "Actor.hpp"
#include "TranslateAble.hpp"
#include "ViewAble.hpp"

// TYM SAYS:  Platform.hpp - I didn't look at this.

namespace Game
{
  // Base class of all Platforms in the game
  class Platform
      : public Actor,
        public ViewAble
  {
  public:
    // Constructs a new Platform using specified world positions and dimensions (percentages).
    Platform(float posX, float posY, float dimX, float dimY);
    // Destructs a Platform.
    ~Platform();

    // Overrides Actor's Resize() method.
    // void Resize() override;
    // Overrides ViewAble's RunViewAble() method.
    void RunViewAble() override;

  private:
    // TODO: Private?
  };
}
