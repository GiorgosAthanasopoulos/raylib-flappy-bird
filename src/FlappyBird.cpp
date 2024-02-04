#include "FlappyBird.hpp"
#include "Config.hpp"

// TODO: fix bound check for bird
// TODO: fix pipe scale
// TODO: implement resize for all entities

FlappyBird::FlappyBird() {
  winSize = {WINDOW_WIDTH, WINDOW_HEIGHT};

  assets = new Assets;
  bird = new Bird(winSize, assets->groundSize, assets->birdSize);

  pipes.push_back({winSize.x / 3,
                   winSize.y - assets->groundSize.y - assets->pipeSize.y,
                   assets->pipeSize.x, assets->pipeSize.y});
  pipes.push_back(
      {2 * winSize.x / 3, 0, assets->pipeSize.x, assets->pipeSize.y});
  pipes.push_back({winSize.x - assets->pipeSize.x,
                   winSize.y - assets->groundSize.y - assets->pipeSize.y,
                   assets->pipeSize.x, assets->pipeSize.y});
}

FlappyBird::~FlappyBird() {
  delete assets;
  delete bird;
}

void FlappyBird::Update() {
  winSize = {(float)GetRenderWidth(), (float)GetRenderHeight()};

  if (bird->dead) {
    if (IsKeyDown(KEY_SPACE)) {
      Reset();
    }
  }
  bird->Update(winSize, assets->groundSize);

  for (int i = 0; i < pipes.size(); ++i) {
    if (CheckCollisionRecs(pipes[i],
                           {bird->pos.x, bird->pos.y, assets->birdSize.x,
                            assets->birdSize.y})) {
      bird->dead = true;
    }
  }
}

void FlappyBird::Reset() { bird->Reset(winSize, assets->groundSize); }

void FlappyBird::Draw() {
  ClearBackground(BACKGROUND_COLOR);
  DrawTexturePro(assets->bg,
                 {0, 0, (float)assets->bg.width, (float)assets->bg.height},
                 {0, 0, winSize.x, winSize.y - assets->groundSize.y}, {0, 0}, 0,
                 BACKGROUND_TINT);
  for (int i = 0; i < winSize.x / assets->groundSize.x; ++i) {
    DrawTexturePro(assets->tiles, assets->grounds[0],
                   {i * assets->groundSize.x, winSize.y - assets->groundSize.y,
                    assets->groundSize.x, assets->groundSize.y},
                   {0, 0}, 0, GROUND_TINT);
  }
  for (int i = 0; i < pipes.size(); ++i) {
    DrawTexturePro(assets->tiles, assets->pipes[0], pipes[i], {0, 0}, 0,
                   PIPE_TINT);
  }
  if (!bird->dead) {
    bird->Draw(assets->bird, assets->birds[0], assets->birdSize);
  } else {
    const char *deadText = "YOU DIED!";
    int fontSize = H1_FONT_SIZE;
    int deadTextWidth = MeasureText(deadText, fontSize);
    DrawText(deadText, winSize.x / 2 - (float)deadTextWidth / 2,
             winSize.y / 2 - (float)fontSize / 2, fontSize, DEAD_TEXT_COLOR);
  }
}
