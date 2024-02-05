#ifndef BIRD_H_
#define BIRD_H_

#include <raylib.h>

class Bird {
private:
  int toJump = 0;         // if 0 no jump otherwise animate jumping
  float jumpDelay = 0.0f; // delay before consecutive jumps
  bool jumping = false;
  bool canJump = true;
  Vector2 birdSize;

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
