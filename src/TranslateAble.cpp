#include "Actor.hpp"
#include <math.h>
#include <stdio.h>
#include "TranslateAble.hpp"

// TYM SAYS:  TranslateAble.hpp - Changed the RunModelAble to remove
// multiplication by 0.01.

using namespace Game;

TranslateAble::TranslateAble(Actor *actor, float speed, float traj)
    : actor(actor),
      speed(speed),
      traj(traj),
      vel(speed * cos(traj), speed * sin(traj))
{
  printf("    TranslateAble::TranslateAble()\n");
  // Current TranslateAble version has nothing further to do in construction.
}

TranslateAble::~TranslateAble()
{
  printf("    TranslateAble::~TranslateAble()\n");
  // Current TranslateAble version has nothing further to do in destruction.
}

void TranslateAble::ChangeSpeed(float ds)
{
  speed += ds;
  vel.x = speed * cos(traj);
  vel.y = speed * sin(traj);
}

void TranslateAble::ChangeTraj(float dt)
{
  traj += dt;
  vel.x = speed * cos(traj);
  vel.y = speed * sin(traj);
}

void TranslateAble::ChangeVel(float dx, float dy)
{
  vel.x += dx;
  vel.y += dy;
  speed = sqrt(vel.x * vel.x + vel.y * vel.y);
  traj = atan2(vel.y, vel.x);
}

void TranslateAble::ChangeVelX(float dx)
{
  vel.x += dx;
  speed = sqrt(vel.x * vel.x + vel.y * vel.y);
  traj = atan2(vel.y, vel.x);
}

void TranslateAble::ChangeVelY(float dy)
{
  vel.y += dy;
  speed = sqrt(vel.x * vel.x + vel.y * vel.y);
  traj = atan2(vel.y, vel.x);
}

void TranslateAble::SetSpeed(float s)
{
  speed = s;
  vel.x = speed * cos(traj);
  vel.y = speed * sin(traj);
}

void TranslateAble::SetTraj(float t)
{
  traj = t;
  vel.x = speed * cos(traj);
  vel.y = speed * sin(traj);
}

void TranslateAble::SetVel(float vx, float vy)
{
  vel.x = vx;
  vel.y = vy;
  speed = sqrt(vel.x * vel.x + vel.y * vel.y);
  traj = atan2(vel.y, vel.x);
}

void TranslateAble::SetVelX(float vx)
{
  vel.x = vx;
  speed = sqrt(vel.x * vel.x + vel.y * vel.y);
  traj = atan2(vel.y, vel.x);
}

void TranslateAble::SetVelY(float vy)
{
  vel.y = vy;
  speed = sqrt(vel.x * vel.x + vel.y * vel.y);
  traj = atan2(vel.y, vel.x);
}

void TranslateAble::RunModelAble()
{
  // TimeChange is stored statically on ModelAble.
  actor->ChangePos(vel.x * timeChange, vel.y * timeChange);
  // TYM SAYS:  I didn't see any reason why these velocities are being
  // multiplied by 0.01. So I deleted those multiples.
  // The velocities should be adjusted as necessary in the config file,
  // instead of adjusting them here.
  // TYM SAYS:  I don't think so. TODO: change these ^ into percentages?
}
