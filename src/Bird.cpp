#include <raylib.h>

#include "Bird.hpp"
#include "Config.hpp"

Bird::Bird(Vector2 winSize, Vector2 groundSize, Vector2 birdSize) {
  pos = {0, winSize.y - groundSize.y - birdSize.y};
  this->birdSize = birdSize;
  movementSpeed = winSize.x / PLAYER_MOVEMENT_SPEED_FACTOR;
}

Bird::~Bird() {}

void Bird::Update(Vector2 winSize, Vector2 groundSize) {
  if (dead) {
    return;
  }

  if (jumpDelay > 0.0f) {
    jumpDelay -= GetFrameTime();
    if (jumpDelay <= 0.0f) {
      jumpDelay = 0.0f;
      canJump = true;
      jumping = false;
      toJump = 0;
    }
  }

  float movementSpeed = this->movementSpeed * GetFrameTime();

  if (IsKeyPressed(KEY_PLAYER_JUMP) && canJump) {
    jumping = true;
    canJump = false;
    toJump = JUMP_PIXELS;
    jumpDelay = JUMP_DELAY;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_RIGHT)) {
    pos.x += movementSpeed;
  }
  if (IsKeyDown(KEY_PLAYER_MOVE_LEFT)) {
    pos.x -= movementSpeed;
  }

  if (!jumping) {
    pos.y += movementSpeed;
  } else {
    pos.y -= movementSpeed;
    toJump -= movementSpeed;
    if (toJump <= 0) {
      jumping = false;
      toJump = 0;
      jumpDelay = JUMP_DELAY;
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
    pos.y = winSize.y - groundSize.y - birdSize.y;
  }
}

void Bird::Reset(Vector2 winSize, Vector2 groundSize) {
  dead = false;
  toJump = 0;
  jumpDelay = 0.0f;
  jumping = false;
  pos = {0, winSize.y - groundSize.y - birdSize.y};
}

void Bird::Draw(Texture2D texture, Rectangle source, Vector2 dim) {
  if (dead) {
    return;
  }

  DrawTexturePro(texture, source, {pos.x, pos.y, dim.x, dim.y}, {0, 0}, 0,
                 BIRD_TINT);
}
