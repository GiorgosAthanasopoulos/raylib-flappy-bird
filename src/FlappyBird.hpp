#ifndef GAME_H_
#define GAME_H_

#include <raylib.h>

#include "Assets.hpp"
#include "Bird.hpp"

class FlappyBird {
private:
  Assets *assets;
  Bird *bird;
  std::vector<Rectangle> pipes;

public:
  Vector2 winSize;

  FlappyBird();
  ~FlappyBird();

  void Update();
  void Resize(Vector2 oldWinSize, Vector2 newWinSize);
  void Draw();

  void Reset();
};

#endif // GAME_H_
