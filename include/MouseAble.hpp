#pragma once
#include <SDL2/SDL.h>
#include <vector>

namespace Game
{
  // Component-class for actors capable of responding to mouse events.
  class MouseAble
  {
  public:
    // Called by Controller to run all MouseAble components in the game.
    static void RunAll(SDL_Event *event);

    // Constructs a MouseAble component.
    MouseAble();
    // Destructs a MouseAble component.
    ~MouseAble();

    // Runs the MouseAble component. Must be overridden by any extending types.
    virtual void RunMouseAble() = 0;

  protected:
    // Static pointer to mouse event for sharing by all mouseAble components.
    static SDL_Event *event;
    // Static vector-collection of pointers to all mouseAbles in the game.
    static std::vector<MouseAble *> mouseAbles;
  };
}
