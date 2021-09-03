#include <algorithm>
#include <stdio.h>
#include "ModelAble.hpp"

using namespace Game;

// Static variables must be initialized in cpp code outside of hpp declaration.
std::vector<ModelAble *> ModelAble::modelAbles;
int ModelAble::timeChange = 0;

// Static function called by the model to run all modelAble actors in the game.
void ModelAble::RunAll(int timeChange)
{
  // Update the timeChange, shared by all modelAbles.
  ModelAble::timeChange = timeChange;
  // Inform all modelAbles of the update.
  for (auto modelAble : modelAbles)
  {
    modelAble->RunModelAble();
  }
}

ModelAble::ModelAble()
{
  printf("    ModelAble::ModelAble()\n");
  // Add the new modeAble to the end of the static collection of modelAbles.
  modelAbles.emplace_back(this);
}

// Deletion of modelAble triggers this destructor, so don't do "delete" op here.
ModelAble::~ModelAble()
{
  printf("    ModelAble::~ModelAble()\n");
  auto it = std::find(modelAbles.begin(), modelAbles.end(), this);
  if (it != modelAbles.end())
  {
    // This quick deletion trick works so long as the vector isn't "ordered."
    std::iter_swap(it, modelAbles.end() - 1);
    modelAbles.pop_back();
  }
}
