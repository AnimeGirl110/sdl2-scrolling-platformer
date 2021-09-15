#include "Config.hpp"
#include <math.h>
#include "Player.hpp"
#include <stdio.h>

// TYM SAYS:  Player.cpp - Didn't make any changes, but needs some clean-up.

using namespace Game;
using namespace Config::Actor::Player;

Player::Player()
    : Actor(POS_X, POS_Y, 0,
            WIDTH,
            HEIGHT),
      RotateAble(this, 0),
      TranslateAble(this, 0, 0),
      AccTransAble(this, 0, 0),
      ViewAble(this->Actor::pos, this->Actor::ori, this->Actor::dim,
               IMAGE_FILENAME)

{
  printf("    Player::Player()\n");
  // Current Player version has nothing further to do during construction.
}

Player::~Player()
{
  //TODO: update

  printf("    Player::~Player()\n");
  // Current Player version has nothing further to do during destruction.
}

// void Player::Resize()
// {
//   printf("    Player::Resize()\n");
//   float dimMinRatio = world->GetDimMin() / world->GetDimMinPrior();
//   float dimY = GetDimY() * dimMinRatio;
//   SetDim(ASPECT_RATIO * dimY, dimY);
//   SetPos(GetPosX() * world->GetDimX() / world->GetDimXPrior(),
//          GetPosY() * world->GetDimY() / world->GetDimYPrior());
//   SetSpeed(GetSpeed() * dimMinRatio);
//   SetAcc(GetAccX() * dimMinRatio, GetAccY() * dimMinRatio);

//   // float dimY = world->GetDimMin() * HEIGHT;
//   // SetDim(ASPECT_RATIO * dimY, dimY);
//   // SetPos(GetPosX() * world->GetDimX() / world->GetDimXPrior(),
//   //        GetPosY() * world->GetDimY() / world->GetDimYPrior());
// }

// TODO: Implement RunKeyAble and RunMouseAble

void Player::RunKeyAble()
{
  int translation = 0;
  if (KeyAble::keyState[KEY_LEFT])
  {
    --translation;
  }
  if (KeyAble::keyState[KEY_RIGHT])
  {
    ++translation;
  }
  TranslateAble::SetVelX(translation * WALKING_SPEED);

  if (KeyAble::keyState[KEY_JUMP])
  {
    // AccTransAble::SetAccByMagAndOri(TRANS_ACC * world->GetDimMin(), GetOri());
    // if (GetSpeed() > MAX_TRANS_SPEED * world->GetDimMin())
    // {
    //   SetSpeed(MAX_TRANS_SPEED * world->GetDimMin());
    // }
    // TODO: This value shouldn't need to be calculated every frame. Store it.
  }
  // else
  // {
  //   AccTransAble::SetAcc();
  // }

  // if (KeyAble::keyState[KEY_SHOOT])
  // {
  //   if (!isShooting)
  //   {
  //     isShooting = true;
  //     // model->AddPlatform(0.1, 0.1, 0.1, 0.1);
  //   }
  // }
  // else
  // {
  //   if (isShooting)
  //   {
  //     isShooting = false;
  //   }
  // }

  // TODO: controllerThrust = (mouseThrust || keyThrust) ? 1 : 0;
}

void Player::RunModelAble()
{ //TODO: update collision detection

  /* Note that this method is needed due to "diamond inheritance" of the
     ModelAble base class through both RotateAble and TranslateAble classes.
     RunModelAble() on those intermediary classes is virtual, and therefore
     ambiguous, when Player inherits from both. It thus becomes necessary to
     clarify how RunModelAble() should behave if/when called on Player. */
  RotateAble::RunModelAble();
  AccTransAble::RunModelAble();
  TranslateAble::RunModelAble();
  // Detect player moving out of bounds, and wrap around if needed.
  // if (Actor::pos.x > world->GetMaxX() - Actor::dimMax && GetVelX() > 0)
  // {
  //   // Player is travelling rightward, so move it to left side.
  //   ChangePosX(-world->GetDimX());
  // }
  // if (Actor::pos.x < world->GetMinX() + Actor::dimMax && GetVelX() < 0)
  // {
  //   // Player is travelling leftward, so move it to right side.
  //   ChangePosX(world->GetDimX());
  // }
  // if (Actor::pos.y > world->GetMaxY() - Actor::dimMax && GetVelY() > 0)
  // {
  //   // Player is travelling downward, so move it to top side.
  //   ChangePosY(-world->GetDimY());
  // }
  // if (Actor::pos.y < world->GetMinY() + Actor::dimMax && GetVelY() < 0)
  // {
  //   // Player is travelling upward, so move it to bottom side.
  //   ChangePosY(world->GetDimY());
  // }
}

void Player::RunMouseAble()
{
  // switch (event->type)
  // {
  // case SDL_MOUSEBUTTONDOWN:
  //   mouseThrust = 1;
  //   break;
  // case SDL_MOUSEBUTTONUP:
  //   mouseThrust = 0;
  //   break;
  // case SDL_MOUSEMOTION:
  //   Actor::pos.a = atan2(event->motion.y - 0.5f * Config::View::WINDOW_DIM_Y,
  //                        event->motion.x - 0.5f * Config::View::WINDOW_DIM_X);
  //   break;
  // case SDL_MOUSEWHEEL:
  //   // ignore
  //   break;
  // }
}

// #include "Acceleration.hpp"
// #include <math.h>
// #include "Position.hpp"
// #include "ThrustAble.hpp"
// #include <stdio.h>
// #include "Velocity.hpp"

// using namespace Game;

// ThrustAble::ThrustAble(Position &pos, class Velocity &vel, Acceleration &acc,
//                        float magThrust, int *controllerThrust)
//     : controllerThrust(controllerThrust), magThrust(magThrust),
//       acc(acc), pos(pos), vel(vel)
// {
//   printf("    ThrustAble::ThrustAble(pos(%.1f, %.1f), vel(%.1f, %.1f), acc(%.1f, %.1f), %.1f, %d)\n",
//          pos.x, pos.y, vel.x, vel.y, acc.x, acc.y, magThrust, *controllerThrust);
// }

// ThrustAble::~ThrustAble()
// {
//   printf("    ThrustAble::~ThrustAble()\n");
// }

// void ThrustAble::RunModelAble()
// {
//   float accMag = (*controllerThrust) * magThrust;
//   acc.x = accMag * cos(pos.a);
//   acc.y = accMag * sin(pos.a);
//   vel.x += acc.x * timeChange;
//   vel.y += acc.y * timeChange;
//   pos.x += vel.x * timeChange;
//   pos.y += vel.y * timeChange;
// }

void Player::RunViewAble()
{
  ViewAble::RunViewAble();
  // if (Actor::pos.x > world->GetMaxX() - Actor::dimMax)
  // {
  //   // Player is on right side.
  //   RunViewAbleAt(Actor::pos.x - world->GetDimX(), Actor::pos.y);
  //   if (Actor::pos.y > world->GetMaxY() - Actor::dimMax)
  //   {
  //     // Player is on lower-right corner.
  //     RunViewAbleAt(Actor::pos.x, Actor::pos.y - world->GetDimY());
  //     RunViewAbleAt(Actor::pos.x - world->GetDimX(),
  //                   Actor::pos.y - world->GetDimY());
  //   }
  //   else if (Actor::pos.y < world->GetMinY() + Actor::dimMax)
  //   {
  //     // Player is on upper-right corner.
  //     RunViewAbleAt(Actor::pos.x, Actor::pos.y + world->GetDimY());
  //     RunViewAbleAt(Actor::pos.x - world->GetDimX(),
  //                   Actor::pos.y + world->GetDimY());
  //   }
  // }
  // else if (Actor::pos.x < world->GetMinX() + Actor::dimMax)
  // {
  //   // Player is on left side.
  //   RunViewAbleAt(Actor::pos.x + world->GetDimX(), Actor::pos.y);
  //   if (Actor::pos.y > world->GetMaxY() - Actor::dimMax)
  //   {
  //     // Player is on lower-left corner.
  //     RunViewAbleAt(Actor::pos.x, Actor::pos.y - world->GetDimY());
  //     RunViewAbleAt(Actor::pos.x + world->GetDimX(),
  //                   Actor::pos.y - world->GetDimY());
  //   }
  //   else if (Actor::pos.y < world->GetMinY() + Actor::dimMax)
  //   {
  //     // Player is on upper-left corner.
  //     RunViewAbleAt(Actor::pos.x, Actor::pos.y + world->GetDimY());
  //     RunViewAbleAt(Actor::pos.x + world->GetDimX(),
  //                   Actor::pos.y + world->GetDimY());
  //   }
  // }
  // else
  // {
  //   if (Actor::pos.y > world->GetMaxY() - Actor::dimMax)
  //   {
  //     // Player is on bottom side.
  //     RunViewAbleAt(Actor::pos.x, Actor::pos.y - world->GetDimY());
  //   }
  //   else if (Actor::pos.y < world->GetMinY() + Actor::dimMax)
  //   {
  //     // Player is on upper side.
  //     RunViewAbleAt(Actor::pos.x, Actor::pos.y + world->GetDimY());
  //   }
  // }
}
