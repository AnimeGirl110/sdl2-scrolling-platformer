#include "Config.hpp"

namespace Game::Config
{
    namespace Actor
    {
        // namespace Asteroid
        // {
        //     float const
        //         ASPECT_RATIO =
        //             1.0;
        //     // Aspect ratio is the image's width divided by height.

        //     float const
        //         HEIGHT_RND_FACTOR =
        //             2.0;

        //     float const
        //         HEIGHTS[4] =
        //             {0.12f, 0.08f, 0.06f, 0.04f};
        //     // Heights are in model units (% of world's min dim).

        //     char const *
        //         IMAGE_FILENAME =
        //             "images/rock.png";

        //     float const
        //         MAX_ANGULAR_SPEED =
        //             0.0025f;
        //     // Specified in radians per millisecond.

        //     float const
        //         MAX_TRANS_SPEED =
        //             0.00015f;
        //     // Given in model units (% of world's min dim) per millisecond.

        //     float const
        //         MIN_TRANS_SPEED =
        //             0.00006f;
        //     // Given in model units (% of world's min dim) per millisecond.

        //     int const
        //         NUM_PHASES =
        //             4;

        //     float const
        //         SPAWNING_FACTOR =
        //             0.40f;
        //     // Specified in model units (% of world's min dim).
        // }

        namespace Background
        {
            char const *
                IMAGE_FILENAME =
                    "images/mountains3.jpg";

            int const
                IMAGE_HEIGHT =
                    848;
            // Specified in pixels.

            int const
                IMAGE_WIDTH =
                    3685;
            // Specified in pixels.

            // float const
            //     ASPECT_RATIO =
            //         (float)IMAGE_WIDTH / (float)IMAGE_HEIGHT;
            // // Aspect ratio is the image's width divided by height.
        }

        namespace Platform
        {
            char const *
                IMAGE_FILENAME =
                    "images/2dplatform.png";
        }

        namespace Player
        {
            // float const
            //     ASPECT_RATIO =
            //         486.0f / 508.0f;
            // // Aspect ratio is the image's width divided by height.

            float const
                WIDTH = 0.06f;
            // Specified in model units (% of world's min dim).

            float const
                HEIGHT =
                    0.06f;
            // Specified in model units (% of world's min dim).

            char const *
                IMAGE_FILENAME =
                    "images/player.png";

            Uint8 const
                KEY_RIGHT =
                    SDL_SCANCODE_D;

            Uint8 const
                KEY_LEFT =
                    SDL_SCANCODE_A;

            Uint8 const
                KEY_JUMP =
                    SDL_SCANCODE_W;

            Uint8 const
                KEY_SHOOT =
                    SDL_SCANCODE_SPACE;

            // float const
            //     MAX_TRANS_SPEED =
            //         0.0004f;
            // Given in model units (% of world's min dim) per millisecond.

            float const
                RUNNING_SPEED =
                    0.0001;
            // Running speed.

            float const
                WALKING_SPEED =
                    0.0075;
            //TODO: adjust speeds.

            float const
                POS_X =
                    0.33;
            // Specified in model units (% of world's min dim).

            float const
                POS_Y =
                    0.5;
            // Specified in model units (% of world's min dim).

            float const
                JUMPING_SPEED =
                    0.00075;

            int
                STAMINA =
                    100;

            // float const
            //     ORI =
            //         0;
            // // Specified in clockwise-radians off positive x-axis.

            // float const
            //     TRANS_ACC =
            //         0.0000004f;
            // // Given in model units (% of world's min dim) per millisecond-squared.

            // float const
            //     VEL_A =
            //         0.0035f;
            // Specified in radians per millisecond.
        }
    }

    namespace Controller
    {
        Uint8 const
            KEY_STOP_GAME =
                SDL_SCANCODE_ESCAPE;
    }

    namespace Model
    {
        int const
            LOOP_TIME_MAX =
                50;
        // Specified in milliseconds.

        // int const
        //     NUM_ASTEROIDS =
        //         10;
        float const
            GRAVITY =
                0.0001;
        //TODO: Adjust later
    }

    namespace Scaffolder
    {
        // Character name of SVG file that the Scaffolder class will use.
        char const
            *SVG_FILENAME =
                "images/tutorial.svg";
    }

    namespace View
    {
        /* INIT_SDL_FLAGS options (which can be joined by | operator) are:
        SDL_INIT_TIMER:          timer subsystem
        SDL_INIT_AUDIO:          audio subsystem
        SDL_INIT_VIDEO:          video subsystem; automatically initializes the
                                 events subsystem
        SDL_INIT_JOYSTICK:       joystick subsystem; automatically initializes
                                 the events subsystem
        SDL_INIT_HAPTIC:         haptic (force feedback) subsystem
        SDL_INIT_GAMECONTROLLER: controller subsystem; automatically initializes
                                 the joystick subsystem
        SDL_INIT_EVENTS:         events subsystem
        SDL_INIT_EVERYTHING:     all of the above subsystems
        SDL_INIT_NOPARACHUTE:    compatibility; this flag is ignored
    */
        Uint32 const
            INIT_SDL_FLAGS =
                SDL_INIT_VIDEO | SDL_INIT_AUDIO;

        /* INIT_WINDOW_FLAGS options (which can be joined by | operator) are :
        SDL_WINDOW_FULLSCREEN:         fullscreen window
        SDL_WINDOW_FULLSCREEN_DESKTOP: fullscreen window at desktop resolution
        SDL_WINDOW_OPENGL:             window usable with an OpenGL context
        SDL_WINDOW_VULKAN:             window usable with a Vulkan instance
        SDL_WINDOW_METAL:              window usable with a Metal instance
        SDL_WINDOW_HIDDEN:             window is not visible
        SDL_WINDOW_BORDERLESS:         no window decoration
        SDL_WINDOW_RESIZABLE:          window can be resized
        SDL_WINDOW_MINIMIZED:          window is minimized
        SDL_WINDOW_MAXIMIZED:          window is maximized
        SDL_WINDOW_INPUT_GRABBED:      window has grabbed input focus
        SDL_WINDOW_ALLOW_HIGHDPI:      window should be created in high-DPI mode
                                       if supported (>= SDL 2.0.1)
    */
        Uint32 const
            INIT_WINDOW_FLAGS =
                0;
        // 0 means no window flags are being set.
    }
}