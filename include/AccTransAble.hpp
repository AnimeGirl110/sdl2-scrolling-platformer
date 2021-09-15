#pragma once
#include "ModelAble.hpp"
#include "Vec2f.hpp"

// TYM SAYS:  AccTransAble.hpp - Looks fine.

namespace Game
{
  // Component-class for actors capable of being translationally accelerated.
  class AccTransAble : virtual public ModelAble
  {
  public:
    // Constructs an AccTransAble component.
    AccTransAble(class TranslateAble *translateAble, float accX, float accY);
    // Destructs an AccTransAble component.
    virtual ~AccTransAble();

    // Get x-component of acceleration
    float GetAccX() { return acc.x; }
    // Get y-component of acceleration
    float GetAccY() { return acc.y; }

    // Set acceleration to zero.
    void SetAcc();
    // Set acceleration.
    void SetAcc(float accX, float accY);
    // Set acceleration by magnitude and orienation.
    void SetAccByMagAndOri(float mag, float ori);
    // Set x acceleration.
    void SetAccX(float accX) { acc.x = accX; }
    // Set y acceleration.
    void SetAccY(float accY) { acc.y = accY; }

    // Called by ModelAble each application cycle to accelerate the actor.
    virtual void RunModelAble() override;

  private:
    // Pointer to the TranslateAble component that can be accelerated
    class TranslateAble *translateAble;
    // Actor's tranlational acceleration
    Vec2f acc;
  };
}
