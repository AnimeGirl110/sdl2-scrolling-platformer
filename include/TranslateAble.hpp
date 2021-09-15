#pragma once
#include "ModelAble.hpp"
#include "Vec2f.hpp"

// TYM SAYS:  TranslateAble.hpp - Looks fine.

namespace Game
{
  // Component-class for actors capable of translating (moving in x, y dims).
  class TranslateAble : virtual public ModelAble
  {
  public:
    // Constructs a TranslateAble component.
    TranslateAble(class Actor *actor, float speed, float traj);
    // Destructs a TranslateAble component.
    virtual ~TranslateAble();

    // Change speed.
    void ChangeSpeed(float ds);
    // Change trajectory.
    void ChangeTraj(float dt);
    // Change x and y velocity.
    void ChangeVel(float dx, float dy);
    // Change x velocity.
    void ChangeVelX(float dx);
    // Change y velocity.
    void ChangeVelY(float dy);

    // Get speed.
    float GetSpeed() { return speed; }
    // Get trajectory.
    float GetTraj() { return traj; }
    // Get x-component of velocity.
    float GetVelX() { return vel.x; }
    // Get y-component of velocity.
    float GetVelY() { return vel.y; }

    // Set Speed.
    void SetSpeed(float s);
    // Set trajectory;
    void SetTraj(float t);
    // Set velocity;
    void SetVel(float vx, float vy);
    // Set x-component of velocity.
    void SetVelX(float vx);
    // Set y-component of velocity.
    void SetVelY(float vy);

    // Called by ModelAble each application cycle to translate the actor.
    virtual void RunModelAble() override;

  private:
    // Pointer to the actor that possesses this component.
    class Actor *actor;
    // Actor's translational speed.
    float speed;
    // Actor's trajectory.
    float traj;
    // Actor's translational velocity, to be coordinated with speed & traj.
    Vec2f vel;
  };
}