#include <raylib.h>

#include "FlappyBird.hpp"

// TODO: #2 fix collisions -- because of scaling there is whitespace in sprites
// causing ghost collisions
// TODO: #1 fix pipe generation algorithm -- sometimes pipes spawn too close to
// one another
// TODO: #3 make window resizable and scale entities accordingly

FlappyBird::FlappyBird() {
  winSize = {WINDOW_WIDTH, WINDOW_HEIGHT};

  assets = new Assets;
  bird = new Bird(winSize, assets->groundSize, assets->birdSize);

  for (int i = 0; i < INITIAL_PIPE_COUNT; ++i) {
    SpawnNewPipe();
  }
}

FlappyBird::~FlappyBird() {
  delete assets;
  delete bird;
}

void FlappyBird::Update() {
  winSize = {(float)GetRenderWidth(), (float)GetRenderHeight()};

  if (bird->dead) {
    if (IsKeyDown(KEY_RESTART)) {
      Reset();
    }
    return;
  }
  bird->Update(winSize, assets->groundSize);

  pipeSpawnDelay -= GetFrameTime();
  if (pipeSpawnDelay <= 0) {
    pipeSpawnDelay = PIPE_SPAWN_DELAY;
    SpawnNewPipe();
  }

  float pipeMovementSpeed =
      winSize.x / PIPE_MOVEMENT_SPEED_FACTOR * GetFrameTime();
  for (long unsigned int i = 0; i < pipes.size(); ++i) {
    pipes[i].x -= pipeMovementSpeed;

    // pipe moved out of viewport -- remove it
    if (pipes[i].x < 0) {
      pipes.erase(pipes.begin() + i);
    }

    if (CheckCollisionRecs(pipes[i],
                           {bird->pos.x, bird->pos.y, assets->birdSize.x,
                            assets->birdSize.y})) {
      bird->dead = true;
    }
  }
}

void FlappyBird::Reset() {
  bird->Reset(winSize, assets->groundSize);
  pipes.clear();
  for (int i = 0; i < INITIAL_PIPE_COUNT; ++i) {
    SpawnNewPipe();
  }
}

void FlappyBird::SpawnNewPipe() {
  float newPipeY = GetRandomValue(0, 10) % 2 == 0
                       ? 0
                       : winSize.y - assets->groundSize.y - assets->pipeSize.y;
  float rightMostPipeX =
      assets->birdSize.x * INITIAL_PIPE_BUFFER_REL_TO_BIRD_SIZE;

  for (int i = 0; i < pipes.size(); ++i) {
    if (pipes[i].x > rightMostPipeX) {
      rightMostPipeX = pipes[i].x;
    }
  }

  float newPipeX =
      GetRandomValue(rightMostPipeX + assets->groundSize.x * 2, winSize.x);
  pipes.push_back({newPipeX, newPipeY, assets->pipeSize.x, assets->pipeSize.y});
}

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
  for (long unsigned int i = 0; i < pipes.size(); ++i) {
    DrawTexturePro(assets->tiles, assets->pipes[0], pipes[i], {0, 0}, 0,
                   PIPE_TINT);
  }

  if (!bird->dead) {
    bird->Draw(assets->bird, assets->birds[0], assets->birdSize);
  } else {
    int deadTextWidth = MeasureText(DEATH_TEXT, DEATH_TEXT_FONT_SIZE);
    DrawText(DEATH_TEXT, winSize.x / 2 - (float)deadTextWidth / 2,
             winSize.y / 2 - (float)DEATH_TEXT_FONT_SIZE / 2,
             DEATH_TEXT_FONT_SIZE, DEAD_TEXT_COLOR);
  }
}
