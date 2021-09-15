#include "Actor.hpp"
#include <algorithm>
#include "Background.hpp"
#include "Camera.hpp"
#include "Config.hpp"
#include "Model.hpp"
#include "ModelAble.hpp"
#include "MVC.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "Scaffolder.hpp"
#include <stdio.h>
#include "World.hpp"

// TYM SAYS:  Model.cpp - Deleted stale old commented lines.
// Deleted code mentioning pastPosX on the background, as unnecessary.
// Didn't make any other changes, but needs some clean-up.

using namespace Game;
using namespace Config::Model;

Model::Model(MVC *mvc)
    : background(nullptr),
      camera(nullptr),
      mvc(mvc),
      player(nullptr),
      scaffolder(nullptr),
      timePrior(0),
      world(nullptr)
{
  printf("  Model::Model()\n");
  // scaffolder = new Scaffolder(*this, dim);
  // Current version of Model has nothing further to do during construction.
}

void Model::AddActors()
{
  // for (auto asteroid : asteroidsToAdd)
  // {
  //   asteroids.emplace_back(asteroid);
  // }
  // asteroidsToAdd.clear();
}

// void Model::AddAsteroid(Asteroid *asteroid)
// {
//   printf("    Model::AddAsteroid()\n");
//   asteroidsToAdd.emplace_back(asteroid);
// }

void Model::AddPlatform(float posX, float posY, float dimX, float dimY)
{
  printf("\n  + NEW PLATFORM\n");
  platforms.emplace_back(new Platform(posX, posY, dimX, dimY));
  //based on percentages?
}

// void Model::CollideAsteroidsLasers()
// {
//   for (auto platform : platforms)
//   {
//     for (auto asteroid : asteroids)
//     {
//       float dx = laser->GetPosX() - asteroid->GetPosX();
//       float dy = laser->GetPosY() - asteroid->GetPosY();
//       float radSum = 0.5 * (laser->GetDimMax() + asteroid->GetDimMax()); // TODO: Use minimum dimension, instead
//       if (dx * dx + dy * dy < radSum * radSum)
//       {
//         if (asteroid->IsBreakAble())
//         {
//           asteroidsToAdd.emplace_back(Asteroid::MakeAsteroid(asteroid));
//           asteroidsToAdd.emplace_back(Asteroid::MakeAsteroid(asteroid));
//           // TODO: How many asteroids should spawn from parent?
//         }
//         DeleteAsteroid(asteroid);
//         DeleteLaser(laser);
//         break;
//       }
//     }
//   }
// }

void Model::DeleteActors()
{
  // for (auto asteroid : asteroidsToDelete)
  // {
  //   auto it = std::find(asteroids.begin(), asteroids.end(), asteroid);
  //   if (it != asteroids.end())
  //   {
  //     // This quick deletion trick works so long as the vector isn't "ordered."
  //     std::iter_swap(it, asteroids.end() - 1);
  //     asteroids.pop_back();
  //     printf("\n  - DELETE ASTEROID\n");
  //     delete asteroid;
  //     asteroid = nullptr;
  //   }
  // }
  // asteroidsToDelete.clear();

  for (auto platform : platformsToDelete)
  {
    auto it = std::find(platforms.begin(), platforms.end(), platform);
    if (it != platforms.end())
    {
      // This quick deletion trick works so long as the vector isn't "ordered."
      std::iter_swap(it, platforms.end() - 1);
      platforms.pop_back();
      printf("\n  - DELETE PLATFORM\n");
      delete platform;
      platform = nullptr;
    }
  }
  platformsToDelete.clear();
}

// void Model::DeleteAsteroid(Asteroid *asteroid)
// {
//   printf("    Model::DeleteAsteroid()\n");
//   asteroidsToDelete.emplace_back(asteroid);
// }

// void Model::DeletePlatform(Platform *platform)
// {
//   printf("    Model::DeletePlatform()\n");
//   platformsToDelete.emplace_back(platform);
// }

void Model::Finalize()
{
  printf("\n  Model::Finalize()\n");

  // Delete the background
  if (background)
  {
    printf("\n  - DELETE BACKGROUND\n");
    delete background;
    background = nullptr;
  }

  // Delete the primary camera
  printf("\n  - DELETE CAMERA\n");
  if (camera)
  {
    delete camera;
    camera = nullptr;
  }

  // Delete the player
  if (player)
  {
    printf("\n  - DELETE PLAYER\n");
    delete player;
    player = nullptr;
  }

  // Delete the platforms
  for (auto platform : platforms)
  {
    printf("\n  - DELETE PLATFORM\n");
    delete platform;
    platform = nullptr;
  }
  platforms.clear();

  // Delete the world
  if (world)
  {
    printf("\n  - DELETE WORLD\n");
    delete world;
    world = nullptr;
  }

  //deletes the scaffolder
  if (scaffolder)
  {
    printf("\n  - DELETE SCAFFOLDER\n");
    delete scaffolder;
    scaffolder = nullptr;
  }
}

bool Model::Initialize()
{
  printf("  Model::Initialize()\n");
  Actor::SetModel(this);
  // Current version of Model has nothing further to do during initialization.
  return true;
}

void Model::MakeInitialActors()
{
  printf("    Model::MakeInitialActors()\n");

  // Create the world, using the screen's full dimensions as recorded.

  printf("\n  + NEW WORLD\n");
  //TODO: Calculate size of worlds (PERCENTS %)
  world = new World(1.0f, 1.0f);
  // Inform all actors of their world.
  Actor::SetWorld(world);

  // Create the game's background.
  printf("\n  + NEW BACKGROUND\n");
  background = new Background();

  // Create the player.
  printf("\n  + NEW PLAYER\n");
  player = new Player();

  // Create the game's primary camera, also using the screen's full dimensions.
  //TODO: Would it still be in pixels or in percentages?
  printf("\n  + NEW CAMERA\n");
  //TODO: Calculate size of camera
  camera = new Camera(0, 0.5f, 0, 1.0f, 1.0f, player);
  // Inform mvc of the camera. Mvc passes it to view, which passes to viewAbles.
  mvc->SetCamera(camera);

  // Create the scaffolder.
  // printf("\n  + NEW SCAFFOLDER\n");
  // Vec2i dim = mvc->GetDim();
  // scaffolder = new Scaffolder(this, &dim);
  // scaffolder->Initialize();

  // Create the asteroids.
  // for (int i = 0; i < NUM_ASTEROIDS; ++i)
  // {
  //   // Static factory function MakeAsteroid() will take care of randomizations.
  //   asteroids.emplace_back(Asteroid::MakeAsteroid());
  // }

  //TODO: Make initial platforms
}

void Model::Resize(int width, int height)
{
  printf("  Model::Resize()\n");
  if (hasBeenResized)
  {
    // world->Resize((float)dim.x, (float)dim.y);
    camera->Resize(width, height);
    // background->Resize();
    // player->Resize();
    // for (auto asteroid : asteroids)
    // {
    //   asteroid->Resize();
    // }
  }
  else
  {
    MakeInitialActors();
    camera->Resize(width, height);
    hasBeenResized = true;
  }
}

void Model::Run()
{
  // Calculate the actual timeChange.
  int timeChange = SDL_GetTicks() - timePrior;
  // Cap the timeChange to LOOP_TIME_MAX specified in config file.
  if (timeChange > LOOP_TIME_MAX)
  {
    timeChange = LOOP_TIME_MAX;
  }
  // Update modelAbles with the timeChange.
  ModelAble::RunAll(timeChange);
  // Detect and handle any collisions between asteroids and lasers.
  // CollideAsteroidsLasers();
  // Add any actors that are to be added to the game.
  AddActors();
  // Delete any actors that are to be terminated.
  DeleteActors();
  // Update timePrior to current time.
  timePrior = SDL_GetTicks();
}