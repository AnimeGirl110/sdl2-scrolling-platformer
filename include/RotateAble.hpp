#pragma once
#include "ModelAble.hpp"

// TYM SAYS:  RotateAble.hpp looks good.

namespace Game
{
  // Component-class for actors capable of rotating.
  class RotateAble : virtual public ModelAble
  {
  public:
    // Constructs a RotateAble component.
    RotateAble(class Actor *actor, float velA);
    // Destructs a RotateAble component.
    virtual ~RotateAble();

    // Change speed.
    void ChangeVel(float dv) { velA += dv; }
    void SetVel(float v) { velA = v; }

    // Called by ModelAble each application cycle to rotate the actor.
    virtual void RunModelAble() override;

  private:
    // Pointer to the actor that possesses this component.
    class Actor *actor;
    // Actor's angular velocity.
    float velA;
  };
}
