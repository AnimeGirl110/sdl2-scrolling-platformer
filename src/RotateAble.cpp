#include "Actor.hpp"
#include "RotateAble.hpp"
#include <stdio.h>

// TYM SAYS:  RotateAble.cpp looks good.

using namespace Game;

RotateAble::RotateAble(class Actor *actor, float velA)
    : actor(actor),
      velA(velA)
{
  printf("    RotateAble::RotateAble()\n");
  // Current RotateAble version has nothing further to do during construction.
}

RotateAble::~RotateAble()
{
  printf("    RotateAble::~RotateAble()\n");
  // Current RotateAble version has nothing further to do during destruction.
}

void RotateAble::RunModelAble()
{
  // TimeChange is stored statically on ModelAble.
  actor->ChangeOri(velA * timeChange);
}
