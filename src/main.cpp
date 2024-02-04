#include <iostream>
#include <raylib.h>
#include <vector>

int main() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  float w = 1080, h = 720;
  InitWindow(w, h, "Flappy Bird");
  InitAudioDevice();
  SetTargetFPS(60);
  SetExitKey(KEY_NULL);

  Texture2D bg = LoadTexture("assets/Background/Background5.png");
  Texture2D tilesTilesheet =
      LoadTexture("assets/Tiles/Style 1/SimpleStyle1.png");
  Vector2 tilesTilesheetImageSize = {128, 112};
  int pipeCountInTilesheet = 4;
  int groundCountInTilesheet = 2;
  float pipeW = tilesTilesheetImageSize.x / pipeCountInTilesheet;
  float pipeH = 80;
  Rectangle pipe[] = {{pipeW * 0, 0, pipeW, pipeH},
                      {pipeW * 1, 0, pipeW, pipeH},
                      {pipeW * 2, 0, pipeW, pipeH},
                      {pipeW * 3, 0, pipeW, pipeH}};
  float groundW = tilesTilesheetImageSize.x / groundCountInTilesheet;
  float groundH = tilesTilesheetImageSize.y - pipeH;
  Rectangle ground[] = {{groundW * 0, pipeH, groundW, groundH},
                        {groundW * 1, pipeH, groundW, groundH}};
  Texture2D playerTilesheet =
      LoadTexture("assets/Player/StyleBird1/AllBird1.png");
  Vector2 playerTilesheetImageSize = {64, 112};
  int playerCountPerRowInTilesheet = 4;
  int playerColumnCountInTilesheet = 7;
  float playerW = playerTilesheetImageSize.x / playerCountPerRowInTilesheet;
  float playerH = playerTilesheetImageSize.y / playerColumnCountInTilesheet;
  std::vector<Rectangle> player;
  for (int y = 0; y < 7; ++y) {
    for (int x = 0; x < 4; ++x) {
      player.push_back({x * playerW, y * playerH, playerW, playerH});
    }
  }
  float scaleFactor = 3.0f;
  float largeScaleFactor = 2 * scaleFactor;
  Vector2 playerPos = {0,
                       h - groundH * scaleFactor - playerH * largeScaleFactor};
  Rectangle pipes[] = {{w / 3, h - groundH * scaleFactor - pipeH * scaleFactor,
                        pipeW * scaleFactor, pipeH * scaleFactor},
                       {2 * w / 3, 0, pipeW * scaleFactor, pipeH * scaleFactor},
                       {w - pipeW * scaleFactor,
                        h - groundH * scaleFactor - pipeH * scaleFactor,
                        pipeW * scaleFactor, pipeH * scaleFactor}};
  bool jumping = false;
  int toJump = 0;

  while (!WindowShouldClose()) {
    w = GetRenderWidth();
    h = GetRenderHeight();
    float movementSpeed = w / 10 * GetFrameTime();

    if (IsKeyDown(KEY_SPACE)) {
      jumping = true;
      toJump = 150;
    }
    if (IsKeyDown(KEY_D)) {
      playerPos.x += movementSpeed;
    }
    if (IsKeyDown(KEY_A)) {
      playerPos.x -= movementSpeed;
    }
    if (!jumping) {
      playerPos.y += movementSpeed;
    } else {
      playerPos.y -= movementSpeed;
      toJump -= movementSpeed;
      if (toJump <= 0) {
        jumping = false;
        toJump = 0;
      }
    }

    if (playerPos.x < 0) {
      playerPos.x = 0;
    }
    if (playerPos.x > w - playerW * largeScaleFactor) {
      playerPos.x = w - playerW * largeScaleFactor;
    }
    if (playerPos.y < 0) {
      playerPos.y = 0;
    }
    if (playerPos.y > h - groundH * scaleFactor - playerH * largeScaleFactor) {
      playerPos.y = h - groundH * scaleFactor - playerH * largeScaleFactor;
    }

    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(0, 0);
    DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height},
                   {0, 0, w, h - groundH * scaleFactor}, {0, 0}, 0, WHITE);
    for (int i = 0; i <= w / groundW * scaleFactor + 1; i++) {
      DrawTexturePro(tilesTilesheet, ground[0],
                     {i * groundW * scaleFactor, h - groundH * scaleFactor,
                      groundW * scaleFactor, groundH * scaleFactor},
                     {0, 0}, 0, WHITE);
    }
    for (int i = 0; i < 3; ++i) {
      DrawTexturePro(tilesTilesheet, pipe[0], pipes[i], {0, 0},
                     i == 1 ? 180 : 0, WHITE);
    }
    DrawTexturePro(playerTilesheet, player[0],
                   {playerPos.x, playerPos.y, playerW * largeScaleFactor,
                    playerH * largeScaleFactor},
                   {0, 0}, 0, WHITE);
    EndDrawing();
  }

  UnloadTexture(playerTilesheet);
  UnloadTexture(tilesTilesheet);
  UnloadTexture(bg);
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
