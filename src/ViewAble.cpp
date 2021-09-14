#include <algorithm>
#include "Camera.hpp"
#include "Math.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "Vec2f.hpp"
#include "Vec2i.hpp"
#include "ViewAble.hpp"

// TYM SAYS:  ViewAble.cpp - Moved initialization of static variables to hpp.
// Removed stale, commented-out code.

using namespace Game;

void ViewAble::DestroyTextures()
{
  printf("      ViewAble::DestroyTextures()\n");
  for (auto texture : textures)
  {
    SDL_DestroyTexture(texture.second);
  }
  textures.clear();
  for (auto viewAble : viewAbles)
  {
    viewAble->NullifyTexture();
  }
}

void ViewAble::RunAll()
{
  for (auto viewAble : viewAbles)
  {
    viewAble->RunViewAble();
  }
}

void ViewAble::SetCamera(Camera *camera)
{
  printf("          ViewAble::SetCamera()\n");
  ViewAble::camera = camera;
}

void ViewAble::SetRenderer(SDL_Renderer *renderer)
{
  printf("    ViewAble::SetRenderer()\n");
  // Replace the old renderer with the new one.
  ViewAble::renderer = renderer;
  // Destroy all existing textures.
  DestroyTextures();
  // Recreate all textures.
  for (auto viewAble : viewAbles)
  {
    viewAble->SetTexture();
  }
}

ViewAble::ViewAble(Vec2f &pos, float &ori, Vec2f &dim,
                   char const *fileName)
    : dim(dim),
      fileName(fileName),
      ori(ori),
      pos(pos),
      texture(nullptr),
      sourceRect(nullptr)
{
  printf("    ViewAble::ViewAble()\n");
  // Set the texture according to fileName.
  SetTexture();
  // Add the new viewAble to the end of the static collection of viewAbles.
  viewAbles.emplace_back(this);
}

// Deletion of viewAble triggers this destructor, so don't do "delete" op here.
ViewAble::~ViewAble()
{
  printf("    ViewAble::~ViewAble()\n");
  auto it = std::find(viewAbles.begin(), viewAbles.end(), this);
  if (it != viewAbles.end())
  {
    // This quick deletion trick works so long as the vector isn't "ordered."
    std::iter_swap(it, viewAbles.end() - 1);
    viewAbles.pop_back();
  }
}

void ViewAble::RunViewAble()
{
  // printf("%f, %f, %f, %f\n", pos.x, pos.y, dim.x, dim.y);
  float cx = 0.5 + pos.x - camera->GetPosX();
  float cy = 0.5 + pos.y - camera->GetPosY();
  //cx is same as pos x
  if (cx - 0.5 * dim.x > 1 || cx + 0.5 * dim.x < 0 ||
      cy - 0.5 * dim.y > 1 || cy + 0.5 * dim.y < 0)
  {
    return;
  }
  // Define the viewAble's bounding destination rectangle.
  SDL_Rect const destinationRect{
      (int)(camera->GetViewDimX() * (cx - dim.x * 0.5)), //cx
      (int)(camera->GetViewDimY() * (cy - dim.y * 0.5)), //cy
      (int)(camera->GetViewDimX() * dim.x),
      (int)(camera->GetViewDimY() * dim.y)};
  if (SDL_RenderCopyEx(
          renderer, texture, sourceRect, &destinationRect,
          (ori - camera->GetOri()) * Math::DEG_PER_RAD,
          NULL, SDL_FLIP_NONE) != 0)
  {
    SDL_Log("ERROR - SDL_RenderCopyEx: %s\n", SDL_GetError());
  }
  // TODO: Ensure this orientation feature works properly.
}

void ViewAble::RunViewAbleAt(float posX, float posY)
{
  float cx = 0.5 + posX - camera->GetPosX();
  float cy = 0.5 + posY - camera->GetPosY();
  //cx is same as pos x
  if (cx - 0.5 * dim.x > 1 || cx + 0.5 * dim.x < 0 ||
      cy - 0.5 * dim.y > 1 || cy + 0.5 * dim.y < 0)
  {
    return;
  }
  // Define the viewAble's bounding destination rectangle.
  SDL_Rect const destinationRect{
      (int)(camera->GetViewDimX() * (cx - dim.x * 0.5)), //cx
      (int)(camera->GetViewDimY() * (cy - dim.y * 0.5)), //cy
      (int)(camera->GetViewDimX() * dim.x),
      (int)(camera->GetViewDimY() * dim.y)};
}

void ViewAble::SetSourceRect(int x, int y, int width, int height)
{
  printf("      ViewAble::SetSourceRect()\n");
  sourceRect->x = x;
  sourceRect->y = y;
  sourceRect->w = width;
  sourceRect->h = height;
}

void ViewAble::SetTexture()
{
  printf("      ViewAble::SetTexture(%s)\n", fileName);
  // Check to see if the same fileName has already been turned into a texture.
  auto it = textures.find(fileName);
  if (it != textures.end())
  {
    // If the texture already exists, just use it instead of creating new one.
    texture = it->second;
  }
  else
  {
    // Load the image file to a surface temporarily.
    SDL_Surface *surface = IMG_Load(fileName);
    if (!surface)
    {
      SDL_Log("ERROR -- IMG_Load(%s)", fileName);
      texture = nullptr;
      return;
    }

    // Use the surface to create a texture.
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    // Free the temporary surface (as it is no longer needed).
    SDL_FreeSurface(surface);
    if (!texture)
    {
      SDL_Log("ERROR -- SDL_CreateTextureFromSurface(%s)", fileName);
      texture = nullptr;
      return;
    }

    // Store the texture in the textures map using fileName as the key.
    textures.emplace(fileName, texture);
  }
}
