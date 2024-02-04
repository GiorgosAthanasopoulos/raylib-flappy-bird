#include <raylib.h>

#include "Config.hpp"
#include "Raylib.hpp"

Raylib::Raylib() {
  SetConfigFlags(0);
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  InitAudioDevice();
  SetTargetFPS(TARGET_FPS);
  SetExitKey(KEY_EXIT);
}

Raylib::~Raylib() {
  CloseAudioDevice();
  CloseWindow();
}
