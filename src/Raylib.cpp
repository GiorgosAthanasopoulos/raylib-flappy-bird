#include <raylib.h>

#include "Config.hpp"
#include "Raylib.hpp"

Raylib::Raylib() {
  SetConfigFlags(WINDOW_FLAGS);
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  InitAudioDevice();
#ifndef DEBUG
  SetTargetFPS(TARGET_FPS);
#endif
  SetExitKey(KEY_EXIT);
}

Raylib::~Raylib() {
  CloseAudioDevice();
  CloseWindow();
}
