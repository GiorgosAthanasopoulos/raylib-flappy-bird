#include "Assets.hpp"
#include "Config.hpp"
#include "Utils.hpp"

Assets::Assets() {
  bg = LoadTexture(BACKGROUND_TEXTURE);
  bgImageSize = {(float)bg.width, (float)bg.height};
  tiles = LoadTexture(TILES_TEXTURE);
  tilesImageSize = {(float)tiles.width, (float)tiles.height};
  bird = LoadTexture(BIRD_TEXTURE);
  birdImageSize = {(float)bird.width, (float)bird.height};

  pipeSize = {tilesImageSize.x / TILES_TILESHEET_PIPE_COUNT,
              TILES_TILESHEET_PIPE_HEIGHT};
  groundSize = {tilesImageSize.x / TILES_TILESHEET_GROUND_COUNT,
                tilesImageSize.y / pipeSize.y};
  birdSize = {birdImageSize.x / BIRD_TILESHEET_BIRD_COUNT_ROW,
              birdImageSize.y / BIRD_TILESHEET_BIRD_COUNT_COL};

  for (int i = 0; i < TILES_TILESHEET_PIPE_COUNT; ++i) {
    pipes.push_back({pipeSize.x * i, 0, pipeSize.x, pipeSize.y});
  }
  for (int i = 0; i < TILES_TILESHEET_GROUND_COUNT; ++i) {
    grounds.push_back(
        {groundSize.x * i, pipeSize.y, groundSize.x, groundSize.y});
  }
  for (int y = 0; y < BIRD_TILESHEET_BIRD_COUNT_COL; ++y) {
    for (int x = 0; x < BIRD_TILESHEET_BIRD_COUNT_ROW; ++x) {
      birds.push_back({x * birdSize.x, y * birdSize.y, birdSize.x, birdSize.y});
    }
  }

  pipeSize *= PIPE_SCALE_FACTOR;
  groundSize *= GROUND_SCALE_FACTOR;
  birdSize *= BIRD_SCALE_FACTOR;
}

Assets::~Assets() {
  UnloadTexture(bird);
  UnloadTexture(tiles);
  UnloadTexture(bg);
}
