#include "MVC.hpp"

//OK

/* Note that defining mvc here invokes its constructor, which automatically
   kickstarts the initialization - run - finalization sequence. */
Game::MVC mvc;

/* Extern "C", as used here, is a linkage specification.
   External code (via JavaScript) needs to call resize() as a C-function.
   But C-functions written in C++ source files are name-mangled by the compiler
   to look like C++ functions, unless protected with an extern "C" specifier. */
extern "C"
{
  // Wrapped and called externally via JavaScript when there is a resize event.
  void resize(int width, int height)
  {
    // Pass call from C-compiled resize function to CPP-compiled mvc object.
    mvc.Resize(width, height);
  }
}

/* Designated at MVC::Initialize as Emscripten's main loop. Note, there is no
   need to specify run() as extern "C", because only called from within C++. */
void run()
{
  // Pass call from C-style run() to CPP-style mvc object.
  mvc.Run();
}

// The main() function is required, but performs no role in this architecture.
int main() {}
