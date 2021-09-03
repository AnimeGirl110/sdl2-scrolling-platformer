#include <cmath>
#include "Math.hpp"
#include <stdlib.h>
#include <time.h>

// TODO: Is <cmath> needed for PI2?  Doesn't seem to be.

float const Math::DEG_PER_RAD = 180 / 3.14159;
float const Math::RAND_MAX_RECIPROCAL = 1.0f / ((float) RAND_MAX);
float const Math::PI2 = M_PI * 2.0f;

void Math::RandomInit()
{
  srand(time(NULL));
}

float Math::GetRandomFloat(float min, float max)
{
  return (min + RAND_MAX_RECIPROCAL * (max - min) * rand());
}
