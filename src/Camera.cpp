#include "Camera.hpp"
#include "Player.hpp"
#include <stdio.h>

using namespace Game;

//coordinates in %
Camera::Camera(float posX, float posY, float ori, float dimX, float dimY, Player *player)
    : Actor(posX, posY, ori, dimX, dimY),
      RotateAble(this, 0),
      TranslateAble(this, 0, 0),
      player(player)
{
  printf("    Camera::Camera()\n");
}

Camera::~Camera()
{
  printf("    Camera::~Camera()\n");
}

void Camera::Resize(int width, int height)
{
  printf("    Camera::Resize()\n");
  // SetDim(world->GetDimX(), world->GetDimY());
  viewDimX = width;
  viewDimY = height;
  // TODO: Adjust the camera's position upon resize.
}

void Camera::RunModelAble()
{
  /* Note that this method is needed due to "diamond inheritance" of the
     ModelAble base class through both RotateAble and TranslateAble classes.
     RunModelAble() on those intermediary classes is virtual, and therefore
     ambiguous, when Camera inherits from both. It thus becomes necessary to
     clarify how RunModelAble() should behave if/when called on Camera. */
  // RotateAble::RunModelAble();
  // TranslateAble::RunModelAble();
  SetPosX(player->GetPosX() + 0.17f);
  // SetPosX(0.5);
  // SetPosY(player->GetPosY());
}
