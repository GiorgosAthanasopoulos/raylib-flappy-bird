#ifndef GAME_H_
#define GAME_H_

#include <raylib.h>

#include "Assets.hpp"
#include "Bird.hpp"
#include "Config.hpp"

class FlappyBird {
private:
  Assets *assets;
  Bird *bird;
  std::vector<Rectangle> pipes;

  float pipeSpawnDelay = PIPE_SPAWN_DELAY;
  float score = 0;

public:
  Vector2 winSize;

  FlappyBird();
  ~FlappyBird();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();

  void Reset();

  void SpawnNewPipe();
};

#endif // GAME_H_
