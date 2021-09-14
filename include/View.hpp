#pragma once
#include <SDL2/SDL.h>
#include "Vec2i.hpp"

// TYM SAYS:  View.hpp looks good.

namespace Game
{
  // Class for managing rendering in the Model-View-Controller paradigm.
  class View
  {
  public:
    // Constructs the application's view.
    View(class MVC *mvc);

    // Called by parent MVC object at end to shut down resources, if any.
    void Finalize();
    // Called by parent MVC object at start to initialize resources, if any.
    bool Initialize();
    // Called when the screen has been resized.
    void Resize(int width, int height);
    // Called each application cycle to perform all rendering.
    void Run();
    // Informs ViewAble class of the camera to be shared by all viewAbles.
    void SetCamera(class Camera *camera);

  private:
    // Reference to the screen's dimensions.
    Vec2i &dim;
    // Pointer to the view's parent MVC object.
    class MVC *mvc;
    // Pointer to current renderer, subject to change when resizing occurs.
    SDL_Renderer *renderer;
    // Pointer to current window, subject to change when resizing occurs.
    SDL_Window *window;
  };
}
