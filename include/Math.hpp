#pragma once

// TYM SAYS:  Math.hpp - I didn't look at this.

// Namespace containing customized math functions and variables.
namespace Math
{
  // Ratio of degrees to radians.
  extern float const DEG_PER_RAD;
  // Reciprocal of the maximum random integer, for ease of calculation.
  extern float const RAND_MAX_RECIPROCAL;
  // Two times pi.
  extern float const PI2;

  // Gets a random float between the stated minimum and maximum values.
  float GetRandomFloat(float min, float max);
  // Initializes the randomizer (only needs to be called once at start).
  void RandomInit();
}

// TODO: Where should the randomizer be initialized? Model? Main?
