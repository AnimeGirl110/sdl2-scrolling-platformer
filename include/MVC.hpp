#pragma once
#include "Controller.hpp"
#include "Model.hpp"
#include "Vec2i.hpp"
#include "View.hpp"

// TYM SAYS:  MVC.hpp looks good. Modified a comment.

namespace Game
{
  // Class implementing the model-view-controller paradigm.
  class MVC
  {
  public:
    // Constructs a new MVC application.
    MVC();

    // Get reference to screen dimensions.
    Vec2i &GetDim() { return dim; }
    // Called when a window resize is detected.
    void Resize(int width, int height);
    // Code to run each application cycle.
    void Run();
    // Informs View which camera to use.
    void SetCamera(class Camera *camera);
    // Stops the game from cycling.
    void Stop();

  private:
    // Called at the application's end to shut down resources.
    void Finalize();
    // Called at the application's start to initialize resources.
    void Initialize();

    // The application's controller.
    Controller controller;
    // The application's model.
    Model model;
    // The application's view.
    View view;

    // Holds dimensions of screen, for sharing with model, view, and controller.
    Vec2i dim;
    // Indicates whether the game loop is currently running.
    bool isRunning;
  };
}
