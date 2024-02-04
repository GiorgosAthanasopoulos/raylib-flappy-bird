#include "Bird.hpp"
#include <raylib.h>

#include "Config.hpp"

Bird::Bird(Vector2 winSize, Vector2 groundSize, Vector2 birdSize) {
  pos = {0, winSize.y - groundSize.y - birdSize.y};
  this->birdSize = birdSize;
  movementSpeed = winSize.x / PLAYER_MOVEMENT_SPEED_FACTOR;
}

Bird::~Bird() {}

void Bird::Update(Vector2 winSize, Vector2 groundSize) {
  if (!dead) {
    if (toJump == 0 && jumpDelay > 0.0f) {
      jumpDelay -= GetFrameTime();
    }
  }

  float movementSpeed = this->movementSpeed * GetFrameTime();

  if (IsKeyDown(KEY_PLAYER_JUMP)) {
    toJump = JUMP_PIXELS;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_RIGHT)) {
    pos.x += movementSpeed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_LEFT)) {
    pos.x -= movementSpeed;
  }

  if (toJump == 0) {
    pos.y += movementSpeed;
  } else {
    pos.y -= movementSpeed;
    toJump -= movementSpeed;
    if (toJump <= 0) {
      toJump = 0;
      jumpDelay = 0.1f;
    }
  }

  if (pos.x < 0) {
    pos.x = 0;
  }
  if (pos.x > winSize.x - birdSize.x) {
    pos.x = winSize.x - birdSize.x;
  }
  if (pos.y < 0) {
    pos.y = 0;
  }
  if (pos.y > winSize.y - groundSize.y - birdSize.y) {
    pos.y = winSize.y = groundSize.y - birdSize.y;
  }
}

void Bird::Reset(Vector2 winSize, Vector2 groundSize) {
  dead = false;
  toJump = 0;
  jumpDelay = 0.0f;
  pos = {0, winSize.y - groundSize.y - birdSize.y};
}

void Bird::Draw(Texture2D texture, Rectangle source, Vector2 dim) {
  DrawTexturePro(texture, source, {pos.x, pos.y, dim.x, dim.y}, {0, 0}, 0,
                 BIRD_TINT);
}
