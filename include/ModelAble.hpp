#pragma once
#include <vector>

// TYM SAYS:  ModelAble.hpp - Declared static variables to be inline,
// so that they can be initialized in the hpp file rather than cpp.

namespace Game
{
  // Base component-class for actors that can be modeled (updated with time).
  class ModelAble
  {
  public:
    // Static function called by the model to run all modelAble actors in game.
    static void RunAll(int timeChange);

    // Constructs a ModelAble component.
    ModelAble();
    // Destructs a ModelAble component.
    virtual ~ModelAble();

    // Runs the ModelAble component. Must be overridden by any extending types.
    virtual void RunModelAble() = 0;

  protected:
    // Static vector-collection of pointers to all modelAbles in the game.
    inline static std::vector<ModelAble *> modelAbles;
    // Static timeChange variable for sharing by all modelAble components.
    inline static int timeChange = 0;
  };
}
