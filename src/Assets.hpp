#ifndef ASSETS_H_
#define ASSETS_H_

#include <raylib.h>
#include <vector>

class Assets {
public:
  Texture2D bg;
  Vector2 bgImageSize;
  Texture2D tiles;
  Vector2 tilesImageSize;
  Texture2D bird;
  Vector2 birdImageSize;

  Vector2 groundSize;
  Vector2 pipeSize;
  Vector2 birdSize;

  std::vector<Rectangle> grounds;
  std::vector<Rectangle> pipes;
  std::vector<Rectangle> birds;

  Assets();
  ~Assets();
};

#endif // ASSETS_H_
