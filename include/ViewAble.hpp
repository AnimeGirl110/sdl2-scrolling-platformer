#pragma once
#include <SDL2/SDL.h>
#include <unordered_map>
#include <vector>

// TYM SAYS:  ViewAble.hpp - Declared static variables to be inline,
// so that they can be initialized in the hpp file rather than cpp.
// Also, corrected an erroneous comment and moved another to a new place.

namespace Game
{
  // Component class for actors capable of being viewed (rendered).
  class ViewAble
  {
  public:
    // Called by View to run all ViewAble components in the game.
    static void RunAll();
    // Called by View to set the active camera.
    static void SetCamera(class Camera *camera);
    // Called by View to set the active renderer.
    static void SetRenderer(class SDL_Renderer *renderer);

    // Constructs a ViewAble component based on percents.
    ViewAble(struct Vec2f &pos, float &ori, struct Vec2f &dim,
             char const *fileName);
    // Destructs a ViewAble object.
    virtual ~ViewAble();

    // Set the ViewAble actor's texture to nullptr.
    void NullifyTexture() { texture = nullptr; }
    // Runs (renders) the ViewAble component. May be overridden.
    virtual void RunViewAble();
    // Runs (renders) the ViewAble component at specified position.
    void RunViewAbleAt(float posX, float posY);
    // Set the source rectangle
    void SetSourceRect(int x, int y, int width, int height);
    // Sets ViewAble compnent's texture by loading fileName, if not yet loaded.
    void SetTexture();

  private:
    // Destroy all textures.
    static void DestroyTextures();

    // Static vector collection of pointers to all viewAbles in the game.
    inline static std::vector<ViewAble *> viewAbles;

    // Static unordered_map collection of pointers to all loaded textures.
    inline static std::unordered_map<char const *, class SDL_Texture *> textures;

    // Reference to the ViewAble actor's dimensions.
    struct Vec2f &dim;
    // File name of the ViewAble's image.
    char const *fileName;
    // Reference to the viewAble actor's orientation.
    float &ori;
    // Reference to the ViewAble actor's position.
    struct Vec2f &pos;

  protected:
    // Static pointer to camera being shared by all viewAbles when rendering.
    inline static class Camera *camera = nullptr;
    // Static pointer to renderer being shared by all viewAbles.
    inline static class SDL_Renderer *renderer = nullptr;
    /* Pointer to SDL_Rect representing boundaries within the image to render.
       Note: Leave sourceRect as nullptr if entire image is to be rendered. */
    SDL_Rect *sourceRect;
    // Pointer to the ViewAble actor's texture.
    class SDL_Texture *texture;
  };
}
