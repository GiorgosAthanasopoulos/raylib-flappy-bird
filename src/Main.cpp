#include "FlappyBird.hpp"
#include "Raylib.hpp"
#include <raylib.h>

int main() {
  Raylib *raylib = new Raylib;
  FlappyBird *game = new FlappyBird;

  while (!WindowShouldClose()) {
    game->Update();
    BeginDrawing();
    DrawFPS(0, 0);
    game->Draw();
    EndDrawing();
  }

  delete game;
  delete raylib;
  return 0;
}
