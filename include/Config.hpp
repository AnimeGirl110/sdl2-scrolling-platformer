#include <SDL2/SDL.h> // for Uint32

#pragma once

/* Note: To reduce time-consuming recompilation whenever configuration settings
are modified, declare the config settings in this .hpp file -- but define
their values in a separate Config.cpp file. */

namespace Game::Config
{
  namespace Actor
  {
    // namespace Asteroid
    // {
    //   // Aspect ratio of image.
    //   extern float const ASPECT_RATIO;

    //   // Maximum height-variability factor.
    //   extern float const HEIGHT_RND_FACTOR;

    //   // Heights of each asteroid phase.
    //   extern float const HEIGHTS[4];

    //   // Location of image file.
    //   extern char const *IMAGE_FILENAME;

    //   // Maximum angular speed, to be randomized.
    //   extern float const MAX_ANGULAR_SPEED;

    //   // Maximum translational speed, to be randomized.
    //   extern float const MAX_TRANS_SPEED;

    //   // Mimimum translational speed, to be randomized.
    //   extern float const MIN_TRANS_SPEED;

    //   // Number of blast phases (size reductions before totally destroyed).
    //   extern int const NUM_PHASES;

    //   // Radius for asteroids to spawn outside.
    //   extern float const SPAWNING_FACTOR;
    // }

    namespace Background
    {
      // Location of image file.
      extern char const *IMAGE_FILENAME;

      // Actual pixel height of the source image.
      extern int const IMAGE_HEIGHT;

      // Actual pixel width of the source image.
      extern int const IMAGE_WIDTH;

      // Aspect ratio of image.
      // extern float const ASPECT_RATIO;
    }

    namespace Platform
    {
      // Location of image file.
      extern char const *IMAGE_FILENAME;

    }

    namespace Player
    {
      // Aspect ratio of image.
      // extern float const ASPECT_RATIO;

      // Width of player.
      extern float const WIDTH;

      // Height of player.
      extern float const HEIGHT;

      // Location of image file.
      extern char const *IMAGE_FILENAME;

      // Key to move right.
      extern Uint8 const KEY_RIGHT;

      // Key to move left.
      extern Uint8 const KEY_LEFT;

      // Key to jump.
      extern Uint8 const KEY_JUMP;

      // Key to rotate counter-clockwise.
      // extern Uint8 const KEY_ROTATE_CCW;

      // Key to rotate clockwise.
      // extern Uint8 const KEY_ROTATE_CW;

      // Key to shoot.
      extern Uint8 const KEY_SHOOT;

      // Running speed.
      extern float const RUNNING_SPEED;

      // Walking speed.
      extern float const WALKING_SPEED;

      // Starting x-position.
      extern float const POS_X;

      // Starting y-position.
      extern float const POS_Y;

      // Speed when player jumps up.
      extern float const JUMPING_SPEED;

      // Amount of stamina player currently has.
      extern int STAMINA;

      // Starting orientation.
      // extern float const ORI;

      // Translational acceleration.
      // extern float const TRANS_ACC;

      // Angular velocity.
      // extern float const VEL_A;
    }
  }

  namespace Controller
  {
    // Designates key to immediately stop the game.
    extern Uint8 const KEY_STOP_GAME;
  }

  namespace Model
  {
    // Maximum allowable time change between cycles.
    extern int const LOOP_TIME_MAX;

    // Number of asteroids.
    // extern int const NUM_ASTEROIDS;

    // Strength of gravity pulling player down on jumps
    extern float const GRAVITY;
  }

  namespace Scaffolder
  {
    // Character name of SVG file that the Scaffolder class will use.
    extern char const *SVG_FILENAME;
  }

  namespace View
  {
    // Specifies which SDL subsystems to activate.
    extern Uint32 const INIT_SDL_FLAGS;

    // Specifies details about window when created.
    extern Uint32 const INIT_WINDOW_FLAGS;
  }

}
