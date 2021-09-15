#pragma once
#include "Vec2i.hpp"

// TYM SAYS:  Controller.hpp looks good.

namespace Game
{
  // Class for managing user input in the Model-View-Controller paradigm.
  class Controller
  {
  public:
    // Constructs the application's controller.
    Controller(class MVC *mvc);

    // Called by parent MVC object at end to shut down resources, if any.
    void Finalize();
    // Called by parent MVC object at start to intialize resources, if any.
    bool Initialize();
    // Called when the screen has been resized.
    void Resize(int width, int height);
    // Called each application cycle to respond to user inputs.
    void Run();

  private:
    // Reference to the screen's dimensions, stored on the parent MVC object.
    Vec2i &dim;
    // Pointer to the controller's parent MVC object.
    class MVC *mvc;
  };
}
