#pragma once
#include "Model.hpp"
#include "Vec2f.hpp"
#include <vector>
#include "World.hpp"

// TYM SAYS:  Actor.hpp - Looks fine.

namespace Game
{
  // Base class for game objects having dimension and position.
  class Actor
  {
  public:
    // Called by Model to specify the model shared by all actors.
    static void SetModel(Model *model);
    // Called by Model to specify the game world shared by all actors.
    static void SetWorld(World *world);

    // Constructs a new Actor & adds it to the static collection of actors.
    Actor(float posX, float posY, float ori, float dimX, float dimY);
    // Destructs an Actor & removes it from the static collection of actors.
    virtual ~Actor();

    // Change x and y dimensions.
    void ChangeDim(float dx, float dy)
    {
      dim.x += dx;
      dim.y += dy;
    }
    // Change x dimension.
    void ChangeDimX(float dx);
    // Change y dimension.
    void ChangeDimY(float dy);
    // Change orientation.
    void ChangeOri(float da) { ori += da; }
    // Change x and y positions.
    void ChangePos(float dx, float dy)
    {
      pos.x += dx;
      pos.y += dy;
    }
    // Change x position.
    void ChangePosX(float dx) { pos.x += dx; }
    // Change y position.
    void ChangePosY(float dy) { pos.y += dy; }

    // Get maximum dimension.
    // float GetDimMax() { return dimMax; }
    // Get x dimension.
    float GetDimX() { return dim.x; }
    // Get y dimension.
    float GetDimY() { return dim.y; }
    // Get orientation.
    float GetOri() { return ori; }
    // Get x position.
    float GetPosX() { return pos.x; }
    // Get y position.
    float GetPosY() { return pos.y; }

    // Resizes actor.  Must be overridden.
    // virtual void Resize() = 0;

    // Set x and y dimensions.
    void SetDim(float x, float y);
    // Set x dimension.
    void SetDimX(float x);
    // Set y dimension.
    void SetDimY(float y);
    // Set orientation.
    void SetOri(float o) { ori = o; }
    // Set x and y positions.
    void SetPos(float x, float y);
    // Set x position.
    void SetPosX(float x) { pos.x = x; }
    // Set y position.
    void SetPosY(float y) { pos.y = y; }

  protected:
    // Static collection of all actors in the game.
    static std::vector<Actor *> actors;
    // Static pointer to the model shared by all actors.
    static Model *model;
    // Static pointer to the game world shared by all actors.
    static World *world;

    // Actor's dimensions (x, y).
    Vec2f dim;
    // Maximum dimension
    // float dimMax;
    // Actor's orientation.
    float ori;
    // Actor's position (x, y).
    Vec2f pos;
  };
}
