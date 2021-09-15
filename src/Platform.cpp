#include "Config.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include <stdio.h>
#include "Camera.hpp"
// #include "SDL/SDL.h"
#include "Math.hpp"

// TYM SAYS:  Platform.cpp - I didn't look at this.

using namespace Game;
using namespace Config::Actor::Platform;

Platform::Platform(float posX, float posY, float dimX, float dimY)
    : Actor(posX, posY, 0, dimX, dimY),
      // TODO: TRANS_SPEED * world->GetDimMin() could be stored for efficiency.
      ViewAble(this->Actor::pos, this->Actor::ori, this->Actor::dim,
               IMAGE_FILENAME)
{
  printf("    Platform::Platform()\n");
  // Current Platform version has nothing further to do during construction.
}

Platform::~Platform()
{
  printf("    Platform::~Platform()\n");
  // Current Platform version has nothing further to do during destruction.
}

// TODO: Need to destroy Platform when it reaches the edge of screen.

// TODO: Need to create Platforms at appropriate times.

// void Platform::Resize()
// {
//   // printf("    Platform::Resize()\n");
//   // float dimMinRatio = world->GetDimMin() / world->GetDimMinPrior();
//   // float dimY = GetDimY() * dimMinRatio;
//   // SetDim(ASPECT_RATIO * dimY, dimY);
//   // SetPos(GetPosX() * world->GetDimX() / world->GetDimXPrior(),
//   //        GetPosY() * world->GetDimY() / world->GetDimYPrior());
//   // SetSpeed(GetSpeed() * dimMinRatio);

//   // // float dimY = world->GetDimMin() * HEIGHT;
//   // // SetDim(ASPECT_RATIO * dimY, dimY);
//   // // SetPos(GetPosX() * world->GetDimX() / world->GetDimXPrior(),
//   // //        GetPosY() * world->GetDimY() / world->GetDimYPrior());
// }

// // void Platform::RunModelAble()
// // {
// //   /* Note that this method is needed due to "diamond inheritance" of the
// //      ModelAble base class through both RotateAble and TranslateAble classes.
// //      RunModelAble() on those intermediary classes is virtual, and therefore
// //      ambiguous, when Asteroid inherits from both. It thus becomes necessary to
// //      clarify how RunModelAble() should behave if/when called on Asteroid. */
// //   // RotateAble::RunModelAble();
// //   TranslateAble::RunModelAble();
// //   // Detect Platform out of bounds.
// //   if (Actor::pos.x > world->GetMaxX() + Actor::dimMax ||
// //       Actor::pos.x < world->GetMinX() - Actor::dimMax ||
// //       Actor::pos.y > world->GetMaxY() + Actor::dimMax ||
// //       Actor::pos.y < world->GetMinY() - Actor::dimMax)
// //   {
// //     model->DeletePlatform(this);
// //     // TODO: This is causing an error. Need to wait until the current loop
// //     // of modelAbles finishes running before model is deleted.
// //     // isRemovable = true;
// //   }
// }

// void Platform::RunViewAble()
// {
//   ViewAble::RunViewAble();
//   // TODO: Is this method necessary?
// }

void Platform::RunViewAble()
{
  ViewAble::RunViewAble();
  // // Define the viewAble's bounding destination rectangle.
  // SDL_Rect const destinationRect{
  //     (int)(0.5 * (camera->GetDimX() - Actor::dim.x * world->GetDimX()) + Actor::pos.x * world->GetDimX() - camera->GetPosX()),
  //     (int)(0.5 * (camera->GetDimY() - Actor::dim.y * world->GetDimY()) + Actor::pos.y * world->GetDimY() - camera->GetPosY()),
  //     (int)(Actor::dim.x * world->GetDimX()), (int)(Actor::dim.y * world->GetDimY())};
  // // Draw the viewAble.
  // if (SDL_RenderCopyEx(
  //         renderer, texture, sourceRect, &destinationRect,
  //         (Actor::ori - camera->GetOri()) * Math::DEG_PER_RAD,
  //         NULL, SDL_FLIP_NONE) != 0)
  // {
  //   SDL_Log("ERROR - SDL_RenderCopyEx: %s\n", SDL_GetError());
  // }
  // // TODO: Ensure this orientation feature works properly.
}
