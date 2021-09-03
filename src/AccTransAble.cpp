#include "AccTransAble.hpp"
#include <stdio.h>
#include "TranslateAble.hpp"
#include <math.h>

using namespace Game;

AccTransAble::AccTransAble(TranslateAble *translateAble, float accX, float accY)
    : translateAble(translateAble),
      acc(accX, accY)
{
  printf("    AccTransAble::AccTransAble()\n");
  // Current AccTransAble version has nothing further to do in construction.
}

AccTransAble::~AccTransAble()
{
  printf("    AccTransAble::~AccTransAble()\n");
  // Current AccTransAble version has nothing further to do in destruction.
}

void AccTransAble::RunModelAble()
{
  // TimeChange is stored statically on ModelAble.
  translateAble->ChangeVel(acc.x * timeChange, acc.y * timeChange);
}

void AccTransAble::SetAcc()
{
  acc.x = acc.y = 0;
}

void AccTransAble::SetAcc(float accX, float accY)
{
  acc.x = accX;
  acc.y = accY;
}

void AccTransAble::SetAccByMagAndOri(float mag, float ori)
{
  acc.x = mag * cos(ori);
  acc.y = mag * sin(ori);
}
