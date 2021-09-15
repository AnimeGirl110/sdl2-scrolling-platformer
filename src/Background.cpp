#include "Background.hpp"
#include "Camera.hpp"
#include "Config.hpp"
#include <stdio.h>
#include "World.hpp"

// TYM SAYS: Background.cpp - Made changes to fix erroneous rendering when
// reach end of the image.
// Deleted pastPosX as unnecessary.
// Deleted stale commented-out code.

using namespace Game;
using namespace Config::Actor::Background;

Background::Background()
    : Actor(0.5f, 0.5f, 0.0f, 1.0f, 1.0f), // TYM SAYS: changed y-dimension to 1.0f
      TranslateAble(this, 0, 0),
      ViewAble(this->Actor::pos,
               this->Actor::ori,
               this->Actor::dim,
               IMAGE_FILENAME)
{
  printf("    Background::Background()\n");

  // Create the background's source rectangle.
  printf("\n  + NEW BACKGROUND SOURCE RECT\n");

  sourceRect = new SDL_Rect();
  this->ViewAble::SetSourceRect(0, 0, IMAGE_WIDTH / 3, IMAGE_HEIGHT);
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

// TYM SAYS: Rewrote this using more descriptive variable names.
void Background::RunModelAble()
{
  float camLeft = this->camera->GetPosX() - 0.5f;
  float numImgRepeats = camLeft / 3.0f;
  float camLeftPctImg = numImgRepeats - (int)numImgRepeats;
  int imgLeft = (int)(camLeftPctImg * IMAGE_WIDTH);
  if (camLeftPctImg > 0.66666)
  {
    primaryImgWidth = (int)((1 - camLeftPctImg) * IMAGE_WIDTH);
    this->ViewAble::SetSourceRect(imgLeft, 0, primaryImgWidth, IMAGE_HEIGHT);
    sourceRect2 = SDL_Rect{0, 0, (int)(0.333333 * IMAGE_WIDTH - primaryImgWidth), IMAGE_HEIGHT};
  }
  else
  {
    primaryImgWidth = (int)(0.333333 * IMAGE_WIDTH);
    this->ViewAble::SetSourceRect(imgLeft, 0, primaryImgWidth, IMAGE_HEIGHT);
    sourceRect2 = SDL_Rect{0, 0, 0, 0};
  }
}

// TYM SAYS: Rewrote this using more descriptive variable names.
void Background::RunViewAble()
{
  int w = (int)(3.0f * primaryImgWidth * camera->GetViewDimX() / IMAGE_WIDTH);
  // printf("%f, %f\n", cx, cy);
  // Define the viewAble's bounding destination rectangle.
  SDL_Rect const destinationRect{0, 0, w, (int)(camera->GetViewDimY())};

  if (SDL_RenderCopyEx(
          renderer, texture, sourceRect, &destinationRect,
          0,
          NULL, SDL_FLIP_NONE) != 0)
  {
    SDL_Log("ERROR - SDL_RenderCopyEx: %s\n", SDL_GetError());
  }

  SDL_Rect const destinationRect2{
      destinationRect.w,
      0,
      (int)(camera->GetViewDimX() - w),
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
