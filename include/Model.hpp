#pragma once
#include <SDL2/SDL.h>
// #include "Vec2i.hpp"
#include <vector>

namespace Game
{
  // Class for managing game state (data) in the Model-View-Controller paradigm.
  class Model
  {
  public:
    // Constructs the application's model.
    Model(class MVC *mvc);

    // Adds a new platform.
    void AddPlatform(float posX, float posY, float dimX, float dimY);
    // Performs actual deletion of any actors marked for deletion.
    void DeleteActors();
    // Adds the platform to vector of platforms requiring deletion.
    void DeletePlatform(class Platform *platform);
    // Called by parent MVC object at end to shut down resources, if any.
    void Finalize();
    // Called by parent MVC object at start to initialize resources, if any.
    bool Initialize();
    // Called when the screen has been resized.
    void Resize(int width, int height);
    // Called each application cycle to run any ModelAble actors.
    void Run();

  private:
    // Perform actual emplacement of any actors marked for addition to game.
    void AddActors();
    // Adds the asteroid to vector of asteroids requiring addition to game.
    // void AddAsteroid(class Asteroid *asteroid);
    // Detect and handle any collisions between asteroids and lasers.
    // void CollideAsteroidsLasers();
    // Adds the asteroid to vector of asteroids requiring deletion.
    // void DeleteAsteroid(class Asteroid *asteroid);
    // Make the game's intial actors.
    void MakeInitialActors();

    // Vector of pointers to all asteroid actors in the game.
    // std::vector<class Asteroid *> asteroids;
    // Vector of pointers to all asteroid actors requiring addition.
    // std::vector<class Asteroid *> asteroidsToAdd;
    // Vector of pointers to all asteroid actors requiring deletion.
    // std::vector<class Asteroid *> asteroidsToDelete;
    // Pointer to game's rigid background actor.
    class Background *background;
    // Pointer to game's primary camera.
    class Camera *camera;
    // Reference to the screen's dimensions, stored on the parent MVC object.
    // Vec2i &dim;
    // Indicates whether there has already been a prior resize event.
    bool hasBeenResized;
    // Vector of pointers to all platform actors in the game.
    std::vector<class Platform *> platforms;
    // Vector of pointers to all platform actors requiring deletion.
    std::vector<class Platform *> platformsToDelete;
    // Pointer to the model's parent MVC object.
    class MVC *mvc;
    // Pointer to game's player actor.
    class Player *player;
    // Pointer to to scaffolder class
    class Scaffolder *scaffolder;
    // Time that the prior game cycle ran.
    Uint32 timePrior;
    // Pointer to game's world.
    class World *world;
  };
}
