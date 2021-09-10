#include "Background.hpp"
#include "Config.hpp"
#include <stdio.h>
#include "World.hpp"
#include "Camera.hpp"

using namespace Game;
using namespace Config::Actor::Background;

Background::Background()
    : Actor(0.5f, 0.5f, 0.0f, 1.0f, 2.0f),
      TranslateAble(this, 0, 0),
      ViewAble(this->Actor::pos,
               this->Actor::ori,
               this->Actor::dim,
               IMAGE_FILENAME),
      pastPosX(0) //todo: camera doesn't exist when this is called?
{
  printf("    Background::Background()\n");

  // Create the background's source rectangle.
  printf("\n  + NEW BACKGROUND SOURCE RECT\n");

  sourceRect = new SDL_Rect();
  this->ViewAble::SetSourceRect(0, 0, IMAGE_WIDTH / 3, IMAGE_HEIGHT);

  // Resize();
}

Background::~Background()
{
  printf("    Background::~Background()\n");

  // Delete the background's source rectangle.
  if (sourceRect)
  {
    //ahrarhgak
    printf("\n  - DELETE BACKGROUND'S SOURCE RECT\n");
    delete sourceRect;
    sourceRect = nullptr;
  }
}

// void Background::RunViewAble()
// { // printf("    Background::~RunViewAble()\n")
//   /*TODO: check if (old) camera.pos.x -  (current) camera.pos.x > 1/2 screen dim |
//        difference in pos.x is greater than 1/2 of background
//     if so, create a new screen after it
//     will this work? */
//   if (this->camera->GetPosX() - pastPosX > this->world->GetDimX() * 0.5)
//   {
//     //assuming going forward
//     pastPosX = this->camera->GetPosX();
//     printf("\n~~~~~~~~~~~~~~~~~~~~~~~~ OVER HALF!\n");
//     //TODO:
//   }
//   ViewAble::RunViewAble();
//   // printf("\n%i, %i, \n", this->ViewAble::sourceRect->w, this->ViewAble::sourceRect->h);
//   // printf("\n%f, %f, %f, %i\n", Actor::pos.x, Actor::pos.y, Actor::dim.x, Actor::dim.y);
// }

void Background::RunModelAble()
{
  float b = (this->camera->GetPosX() - 0.5f) / 3.0f;
  float c = b - (int)(b);
  float left = c * 3; // left position.
  if (left > 2.0f)
  {
    int leftPx = (int)(left * IMAGE_WIDTH / 3.0f);
    int width = (int)(IMAGE_WIDTH / 3.0f * (3.0f - left));
    this->ViewAble::SetSourceRect(leftPx, 0, width, IMAGE_HEIGHT);
    sourceRect2 = SDL_Rect{0, 0, (int)(IMAGE_WIDTH / 3.0f - width), IMAGE_HEIGHT};
  }
  else
  {
    int leftPx = (int)(left * IMAGE_WIDTH / 3.0f);
    int width = (int)(IMAGE_WIDTH / 3.0f);
    this->ViewAble::SetSourceRect(leftPx, 0, width, IMAGE_HEIGHT);
    sourceRect2 = SDL_Rect{0, 0, 0, 0};
  }

  if (left < 0)
  {
    //gives us left edge of new image.
    left += 2.0f;
  }
  else if (left > 2.0f)
  {
    left -= 2.0f;
  }
}

void Background::RunViewAble()
{
  // printf("%f, %f\n", cx, cy);
  // Define the viewAble's bounding destination rectangle.
  SDL_Rect const destinationRect{
      0, //cx
      0, //cy
      (int)(camera->GetViewDimX()) - sourceRect2.w,
      (int)(camera->GetViewDimY())};
  if (SDL_RenderCopyEx(
          renderer, texture, sourceRect, &destinationRect,
          0,
          NULL, SDL_FLIP_NONE) != 0)
  {
    SDL_Log("ERROR - SDL_RenderCopyEx: %s\n", SDL_GetError());
  }
  SDL_Rect const destinationRect2{
      destinationRect.w, //cx
      0,                 //cy
      (int)(camera->GetViewDimX()),
      (int)(camera->GetViewDimY())};
  if (SDL_RenderCopyEx(
          renderer, texture, &sourceRect2, &destinationRect2,
          0,
          NULL, SDL_FLIP_NONE) != 0)
  {
    SDL_Log("ERROR - SDL_RenderCopyEx: %s\n", SDL_GetError());
  }
  // TODO: Ensure this orientation feature works properly.
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
