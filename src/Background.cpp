#include "Background.hpp"
#include "Config.hpp"
#include <stdio.h>
#include "World.hpp"

using namespace Game;
using namespace Config::Actor::Background;

Background::Background()
    : Actor(0, 0, 0, world->GetDimX(), world->GetDimY()),
      ViewAble(this->Actor::pos, this->Actor::ori, this->Actor::dim,
               IMAGE_FILENAME)
{
  printf("    Background::Background()\n");

  // Create the background's source rectangle.
  printf("\n  + NEW BACKGROUND SOURCE RECT\n");
  sourceRect = new SDL_Rect();
  // Resize();
}

Background::~Background()
{
  printf("    Background::~Background()\n");

  // Delete the background's source rectangle.
  if (sourceRect)
  {
    printf("\n  - DELETE BACKGROUND'S SOURCE RECT\n");
    delete sourceRect;
    sourceRect = nullptr;
  }
}

// void Background::Resize()
// {
//   printf("    Background::Resize()\n");
//   float worldAspectRatio = world->GetDimX() / world->GetDimY();
//   if (worldAspectRatio > ASPECT_RATIO)
//   {
//     SetSourceRect(0, 0,
//                   IMAGE_WIDTH, (int)(IMAGE_WIDTH / worldAspectRatio + 0.5));
//   }
//   else
//   {
//     SetSourceRect(0, 0,
//                   (int)(IMAGE_HEIGHT * worldAspectRatio + 0.5), IMAGE_HEIGHT);
//   }
//   SetDim(world->GetDimX(), world->GetDimY());
// }
