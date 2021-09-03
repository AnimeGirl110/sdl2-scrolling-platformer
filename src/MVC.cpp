#include "Camera.hpp"
#include <emscripten/emscripten.h>
#include "MVC.hpp"
#include <stdio.h>

using namespace Game;

// Declare run(), which is defined in Main.cpp & referenced in MVC::Initialize.
void run();

MVC::MVC()
    : controller(this),
      model(this),
      view(this),
      isRunning(true)
{
  printf("MVC::MVC()\n");
  // MVC's constructor automatically triggers initialization.
  Initialize();
}

void MVC::Finalize()
{
  printf("\nMVC::Finalize()\n");
  // Cancel the main loop.
  emscripten_cancel_main_loop();
  // Then call on the model, view, and controller to finalize in turn.
  model.Finalize();
  view.Finalize();
  controller.Finalize();
}

void MVC::Initialize()
{
  printf("\nMVC::Initialize()\n");
  // Note: View must be initialized before model, so that renderer is set.
  if (view.Initialize() && controller.Initialize() && model.Initialize())
  {
    // Specify run(), located in Main.cpp, as Emscripten's main loop.
    emscripten_set_main_loop(run, 0, 0);
    printf("\nMVC::Run() ...\n");
  }
  else
  {
    printf("ERROR @ MVC::Initialize(). Failure to initialize.\n");
    // Proceed immediately to finalizaiton if there is a problem initializing.
    Finalize();
  }
}

void MVC::Resize(int width, int height)
{
  printf("\nMVC::Resize(%d, %d)\n", width, height);
  // Store the new dimensions.
  dim.x = width;
  dim.y = height;
  // Note: View must be resized before model, so that renderer is set.
  view.Resize(width, height);
  controller.Resize(width, height);
  model.Resize(width, height);
}

void MVC::Run()
{
  if (isRunning)
  {
    // So long as game is running, sequentially run controller, model, and view.
    controller.Run();
    model.Run();
    view.Run();
  }
  else
  {
    // If the game is no longer running, then proceed to finalization.
    Finalize();
  }
}

void MVC::SetCamera(Camera *camera)
{
  printf("      MVC::SetCamera()\n");
  // MVC simply passes responsibility for setting the camera to the view.
  view.SetCamera(camera);
}

void MVC::Stop()
{
  printf("\nMVC::Stop()\n");
  isRunning = false;
}
