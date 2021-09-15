#include "Camera.hpp"
#include "Config.hpp"
#include "MVC.hpp"
#include <stdio.h>
#include "View.hpp"
#include "ViewAble.hpp"

// TYM SAYS:  View.cpp looks good.

// TODO: Does the SDL image subsystem need to be initialized and quit?

using namespace Game;
using namespace Config::View;

View::View(MVC *mvc)
    : dim(mvc->GetDim()),
      mvc(mvc),
      renderer(nullptr),
      window(nullptr)
{
  printf("  View::View()\n");
  // Current version of View has nothing further to do during construction.
}

void View::Finalize()
{
  printf("\n  View::Finalize()\n");
  /* Note: A warning may be repeatedly logged to console when finalizing view:
        Calling stub instead of sigaction()
     This appears to be caused when SDL makes internal calls to
     sigaction.  When emscripten is building with ASSERTIONS, it will warn about
     such calls, because they are (apparently) not supported. This seems to
     cause no apparently problems, however, so the "Calling stub" warnings can
     presumably be safely ignored. */
  printf("    Ignore the following (possible) 'sigaction()' warnings...\n");
  // Destroy the window's rendering context / free associated textures.
  SDL_DestroyRenderer(renderer);
  // Destroy the SDL window.
  SDL_DestroyWindow(window);
  // Clean up all initialized SDL subsystems.
  SDL_Quit();
}

bool View::Initialize()
{
  printf("  View::Initialize()\n");
  /* Note: A warning may be repeatedly logged to console when initializing view:
        Calling stub instead of sigaction()
     This appears to be caused when SDL_Init makes internal calls to
     sigaction.  When emscripten is building with ASSERTIONS, it will warn about
     such calls, because they are (apparently) not supported. This seems to
     cause no apparently problems, however, so the "Calling stub" warnings can
     presumably be safely ignored. */
  printf("    Ignore the following (possible) 'sigaction()' warnings...\n");
  // Initialize SDL library with INIT_SDL_FLAGS specified in Config file.
  if (SDL_Init(INIT_SDL_FLAGS) != 0)
  {
    SDL_Log("ERROR -- SDL_Init(): %s", SDL_GetError());
    return false;
  }
  // Initialization was successful.
  return true;
}

void View::Resize(int width, int height)
{
  printf("  View::Resize()\n");
  // Destroy the window's rendering context / free associated textures.
  if (renderer)
  {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
  }
  // Destroy the SDL window.
  if (window)
  {
    SDL_DestroyWindow(window);
    window = nullptr;
  }
  // Create a new window and renderer.
  if (SDL_CreateWindowAndRenderer(dim.x, dim.y, INIT_WINDOW_FLAGS,
                                  &window, &renderer) != 0)
  {
    SDL_Log("ERROR -- SDL_CreateWindowAndRenderer(): %s", SDL_GetError());
    mvc->Stop();
  }
  // Update the ViewAble class's renderer to be shared by all viewAbles.
  ViewAble::SetRenderer(renderer);
}

void View::Run()
{
  /* Note that the renderer should be cleared even if a background image is
  being drawn every frame, because clearing improves performance by allowing
  unneeded frame data to be discarded. */
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  /*****************************************************************************
  // Uncomment this code to test basic SDL drawing

  SDL_Rect rect1{100, 100, 100, 100};
  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
  SDL_RenderFillRect(renderer, &rect1);
  *****************************************************************************/

  // Call on the ViewAbles to render themselves.
  ViewAble::RunAll();

  // Update the screen with the newly performed renderings.
  SDL_RenderPresent(renderer);
}

void View::SetCamera(Camera *camera)
{
  printf("        View::SetCamera()\n");
  ViewAble::SetCamera(camera);
}
