#include "Scaffolder.hpp"
#include "Camera.hpp"
#include "Config.hpp"
#include "Model.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// TYM SAYS:  Scaffolder.cpp - I didn't look at this.

using namespace Game;
using namespace Config::Scaffolder;
using namespace std;

Scaffolder::Scaffolder(Model *model, Vec2i *worldDim)
    : model(model), worldDim(worldDim)
{
}

void Scaffolder::AddTypes()
{
  types.emplace("platform", TYPE_PLATFORM);
  types.emplace("ground", TYPE_GROUND);
  types.emplace("enemy", TYPE_ENEMY);
  types.emplace("checkpoint", TYPE_CHECKPOINT);
  types.emplace("bConveyor", TYPE_CONVEYOR);
  types.emplace("tJump", TYPE_TUTORIALJUMP);
  types.emplace("tSprintjump", TYPE_TUTORIALSPRINTJUMP);
  types.emplace("tFight", TYPE_TUTORIALFIGHT);
  types.emplace("tAbilities", TYPE_TUTORIALABILITIES);
  types.emplace("tDash", TYPE_TUTORIALDASH);
  types.emplace("movingPlatform", TYPE_MOVINGPLATFORM);
  types.emplace("abilityDropper", TYPE_ABILITYDROPPER);
  types.emplace("levelDoor", TYPE_LEVELDOOR);

  //TODO: Add all other types here
}

string Scaffolder::FindFromSVG(string text, const char *ch, size_t found, int start, int end)
{
  size_t foundStart = text.find(ch, found + 1);
  size_t foundEnd = text.find("\"", foundStart + start);
  string str = text.substr(foundStart + start, foundEnd - foundStart - end);
  return str;
}

// float Scaffolder::ConvertToPercent(float)
// {
//   //TODO: divide num by camera dim or world dim?
// }

void Scaffolder::Initialize()
{
  AddTypes();

  ifstream f(SVG_FILENAME);
  string text;
  if (f)
  {
    ostringstream oss;
    oss << f.rdbuf();
    text = oss.str();

    size_t found = text.find("<rect");
    while (found != string::npos)
    {
      //gets data from the svg by calling function
      string xStr = FindFromSVG(text, "x=", found, 3, 4);
      string yStr = FindFromSVG(text, "y=", found, 3, 4);
      string widthStr = FindFromSVG(text, "width=", found, 7, 8);
      string heightStr = FindFromSVG(text, "height=", found, 8, 9);
      string typeStr = FindFromSVG(text, "type=", found, 6, 6);

      //is this necessary
      float worldDimX = float(worldDim->x);
      float worldDimY = float(worldDim->y);

      ///convert platforms to % of screen
      float posX = stof(xStr) / worldDimX;
      float posY = stof(yStr) / worldDimY;
      float width = stof(widthStr) / worldDimX;
      float height = stof(heightStr) / worldDimY;

      switch (types[typeStr])
      {
      case TYPE_PLATFORM:
        model->AddPlatform(posX, posY, width, height);
        break;
      case TYPE_GROUND:
        break;
      case TYPE_ENEMY:
        break;
      default:
        cout << "ignoring " << typeStr << endl;
        break;
      }

      // cout << xStr << ", " << yStr << ", " << widthStr << ", " << heightStr << ", " << typeStr << endl;
      found = text.find("<rect", found + 1);
    }
  }
}

//FOR REFERENCE:
// size_t foundX = text.find("x=", found + 1);
// size_t foundXEnd = text.find("\"", foundX + 3);
// string xStr = text.substr(foundX + 3, foundXEnd - foundX - 4);
