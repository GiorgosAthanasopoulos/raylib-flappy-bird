#include <raylib.h>

#include "FlappyBird.hpp"
#include "Raylib.hpp"

int main() {
  Raylib *raylib = new Raylib;
  FlappyBird *game = new FlappyBird;

  while (!WindowShouldClose()) {
    game->Update();
    BeginDrawing();
#ifdef DEBUG
    DrawFPS(0, 0);
#endif
    game->Draw();
    EndDrawing();
  }

  delete game;
  delete raylib;
  return 0;
}
