#include <algorithm>
#include "KeyAble.hpp"
#include <stdio.h>

// TYM SAYS:  KeyAble.cpp - Moved initialization of static variables to hpp.

using namespace Game;

void KeyAble::RunAll(Uint8 const *keyState)
{
  // Update the keyState, shared by all keyAbles.
  KeyAble::keyState = keyState;
  // Inform all keyAbles of the update.
  for (auto keyAble : keyAbles)
  {
    keyAble->RunKeyAble();
  }
}

KeyAble::KeyAble()
{
  printf("    KeyAble::KeyAble()\n");
  // Add the new keyAble to the end of the static collection of keyAbles.
  keyAbles.emplace_back(this);
}

// Deletion of a keyAble triggers this destructor, so don't do "delete" op here.
KeyAble::~KeyAble()
{
  printf("    KeyAble::~KeyAble()\n");
  auto it = std::find(keyAbles.begin(), keyAbles.end(), this);
  if (it != keyAbles.end())
  {
    // This quick deletion trick works so long as the vector isn't "ordered."
    std::iter_swap(it, keyAbles.end() - 1);
    keyAbles.pop_back();
  }
}
