#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <unordered_map>

namespace Game
{
  // Component class for actors capable of being viewed (rendered).
  class ViewAble
  {
  public:
    // Called by View to run all ViewAble components in the game.
    static void RunAll();
    // Called by Model to set the active camera.
    static void SetCamera(class Camera *camera);
    // Called by View to set the active renderer.
    static void SetRenderer(class SDL_Renderer *renderer);
    //Called by View to set worldDim.
    //static void SetWorldDim(struct Vec2i *vect);

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
    static std::vector<ViewAble *> viewAbles;

    // Static vector of the dimensions of the screen.
    // static struct Vec2i *worldDim;

    // Static unordered_map collection of pointers to all loaded textures.
    static std::unordered_map<char const *, class SDL_Texture *> textures;
    /* Pointer to SDL_Rect representing boundaries within the image to render.
     
Note: Leave sourceRect as nullptr if entire image is to be rendered. */

    // Reference to the ViewAble actor's dimensions.
    struct Vec2f &dim;
    //
    char const *fileName;
    // Reference to the viewAble actor's orientation.
    float &ori;
    // Reference to the ViewAble actor's position.
    struct Vec2f &pos;

  protected:
    // Static pointer to camera being shared by all viewAbles when rendering.
    static class Camera *camera;
    // Static pointer to renderer being shared by all viewAbles.
    static class SDL_Renderer *renderer;
    SDL_Rect *sourceRect;
    // Pointer to the ViewAble actor's texture.
    class SDL_Texture *texture;
  };
}
