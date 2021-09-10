#pragma once
#include "Actor.hpp"
#include "TranslateAble.hpp"
#include "ViewAble.hpp"

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

    // Overrides Actor's Resize() method.
    // void Resize() override;

    // overrides background's viewable function.
    void RunViewAble() override;

    void RunModelAble() override;

    SDL_Rect sourceRect2;
    // value of camera's past x-position -- to be used in calculations.
    float pastPosX; //in public so model can see
  };
}
