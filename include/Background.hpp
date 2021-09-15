#pragma once
#include "Actor.hpp"
#include "TranslateAble.hpp"
#include "ViewAble.hpp"

// TYM SAYS: Background.hpp - Made changes to fix erroneous rendering when
// reach end of the image.
// Deleted pastPosX as unnecessary.
// Deleted stale commented-out code.

namespace Game
{
  class Background
      : public Actor,
        public TranslateAble,
        public ViewAble
  {
  public:
    // Constructs a background
    Background();
    // Destructs a background
    ~Background();

    // overrides background's viewable function.
    void RunViewAble() override;

    void RunModelAble() override;

    SDL_Rect sourceRect2;
    int primaryImgWidth = 0; // TYM SAYS: Added this variable.
  };
}
