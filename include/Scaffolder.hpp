#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include "Vec2i.hpp"

namespace Game
{
  class Scaffolder
  {
  public:
    enum TYPE
    {
      TYPE_PLATFORM,
      TYPE_GROUND,
      TYPE_ENEMY,
      TYPE_CHECKPOINT,
      TYPE_CONVEYOR,
      TYPE_TUTORIALJUMP,
      TYPE_TUTORIALSPRINTJUMP,
      TYPE_TUTORIALFIGHT,
      TYPE_TUTORIALABILITIES,
      TYPE_TUTORIALDASH,
      TYPE_MOVINGPLATFORM,
      TYPE_ABILITYDROPPER,
      TYPE_LEVELDOOR
    };
    //constructor
    Scaffolder(class Model *model, Vec2i *worldDim);
    //looks through the svg and creates the level
    void Initialize();

  private:
    void AddTypes();
    std::string FindFromSVG(std::string text, const char *ch, size_t found, int start, int end);
    // float ConvertToPercent(float num);

    //pointer to the model
    class Model *model;
    //pointer to the world's dimensions
    Vec2i *worldDim;
    //list of all the actor types in the game
    std::unordered_map<std::string, TYPE> types;
  };
}
