#pragma once
#include <SDL2/SDL.h>
#include <vector>

// TYM SAYS:  KeyAble.hpp - Declared static variables to be inline,
// so that they can be initialized in the hpp file rather than cpp.

namespace Game
{
  // Component-class for actors capable of responding to keyboard's state.
  class KeyAble
  {
  public:
    // Called by Controller to run all KeyAble components in the game.
    static void RunAll(Uint8 const *keyState);

    // Constructs a KeyAble component.
    KeyAble();
    // Destructs a KeyAble component.
    virtual ~KeyAble();

    // Runs the KeyAble component. Must be overridden by any extending types.
    virtual void RunKeyAble() = 0;

  protected:
    // Static vector-collection of pointers to all keyAbles in the game.
    inline static std::vector<KeyAble *> keyAbles;
    // Static pointer to current keyState for sharing by all keyAble components.
    inline static Uint8 const *keyState = nullptr;
  };
}