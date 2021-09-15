#include <algorithm>
#include "MouseAble.hpp"
#include <stdio.h>

// TYM SAYS:  MouseAble.cpp - Moved initialization of static variables to hpp.

using namespace Game;

void MouseAble::RunAll(SDL_Event *event)
{
  // Update the mouse event, shared by all mouseAbles.
  MouseAble::event = event;
  // Inform all mouseAbles of the update.
  for (auto mouseAble : mouseAbles)
  {
    mouseAble->RunMouseAble();
  }
}

MouseAble::MouseAble()
{
  printf("    MouseAble::MouseAble()\n");
  // Add the new mouseAble to the end of the static collection of mouseAbles.
  mouseAbles.emplace_back(this);
}

// Deletion of mouseAble triggers this destructor, so don't do "delete" op here.
MouseAble::~MouseAble()
{
  printf("    MouseAble::~MouseAble()\n");
  auto it = std::find(mouseAbles.begin(), mouseAbles.end(), this);
  if (it != mouseAbles.end())
  {
    // This quick deletion trick works so long as the vector isn't "ordered."
    std::iter_swap(it, mouseAbles.end() - 1);
    mouseAbles.pop_back();
  }
}
