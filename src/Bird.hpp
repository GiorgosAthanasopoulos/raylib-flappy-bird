#ifndef BIRD_H_
#define BIRD_H_

#include <raylib.h>

#include "Config.hpp"

class Bird {
private:
  Vector2 birdSize;
  int toJump = 0;
  float jumpDelay = 0.0f;

public:
  Vector2 pos;
  bool dead = false;

  Bird(Vector2 winSize, Vector2 groundSize, Vector2 birdSize);
  ~Bird();

  void Update(Vector2 winSize, Vector2 groundSize);
  void Draw(Texture2D texture, Rectangle source, Vector2 dim);

  void Reset(Vector2 winSize, Vector2 groundSize);
};

#endif // BIRD_H_
