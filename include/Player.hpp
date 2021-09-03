#pragma once
#include "Actor.hpp"
#include "KeyAble.hpp"
#include "MouseAble.hpp"
#include "RotateAble.hpp"
#include "TranslateAble.hpp"
#include "AccTransAble.hpp"
#include "ViewAble.hpp"

namespace Game
{
  class Player
      : public Actor,
        public KeyAble,
        public MouseAble,
        public RotateAble,
        public TranslateAble,
        public AccTransAble,
        public ViewAble
  {
  public:
    // Constructs a new player.
    Player();
    // Destructs a player.
    ~Player();

    // Overrides Actor's Resize() method.
    // void Resize() override;
    // Overrides KeyAble's Run method.
    void RunKeyAble() override;
    // Runs the actor's (multiple) ModelAble components.
    void RunModelAble() override;
    // Overrides MouseAble's Run method.
    void RunMouseAble() override;
    // Overrides ViewAble's RunViewAble() method.
    void RunViewAble() override;

  private:
    // bool isShooting;
  };
}
