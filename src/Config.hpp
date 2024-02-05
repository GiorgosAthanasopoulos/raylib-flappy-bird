#ifndef CONFIG_H_
#define CONFIG_H_

#include <raylib.h>

// WINDOW
#define WINDOW_FLAGS 0
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "Flappy Bird"
#define TARGET_FPS 60

// KEYBINDS
#define KEY_EXIT KEY_NULL
#define KEY_RESTART KEY_SPACE
#define KEY_PLAYER_JUMP KEY_W
#define KEY_PLAYER_MOVE_RIGHT KEY_D
#define KEY_PLAYER_MOVE_LEFT KEY_A

// COLORS
#define BACKGROUND_COLOR WHITE
#define BACKGROUND_TINT WHITE
#define GROUND_TINT WHITE
#define PIPE_TINT WHITE
#define BIRD_TINT WHITE
#define DEAD_TEXT_COLOR RED

// PLAYER
#define PLAYER_MOVEMENT_SPEED_FACTOR 6
#define JUMP_PIXELS 150
#define JUMP_DELAY 0.5f

// ASSETS
#define ASSETS "assets/"
#define BACKGROUND_TEXTURE ASSETS "Background/Background5.png"
#define TILES_TEXTURE ASSETS "Tiles/Style 1/SimpleStyle1.png"
#define BIRD_TEXTURE ASSETS "Player/StyleBird1/AllBird1.png"

// TILESHEETS
#define LARGE_SCALE_FACTOR 3
#define XLARGE_SCALE_FACTOR 2 * LARGE_SCALE_FACTOR
#define PIPE_SCALE_FACTOR LARGE_SCALE_FACTOR
#define GROUND_SCALE_FACTOR LARGE_SCALE_FACTOR
#define BIRD_SCALE_FACTOR XLARGE_SCALE_FACTOR
#define TILES_TILESHEET_PIPE_COUNT 4
#define TILES_TILESHEET_PIPE_HEIGHT 80
#define TILES_TILESHEET_GROUND_COUNT 2
#define BIRD_TILESHEET_BIRD_COUNT_ROW 4
#define BIRD_TILESHEET_BIRD_COUNT_COL 7

// UI
#define H1_FONT_SIZE 100
#define DEATH_TEXT "YOU DIED!"
#define DEATH_TEXT_FONT_SIZE H1_FONT_SIZE

// GAME
#define PIPE_MOVEMENT_SPEED_FACTOR 12
#define PIPE_SPAWN_DELAY 3.0f
#define INITIAL_PIPE_BUFFER_REL_TO_BIRD_SIZE 3
#define INITIAL_PIPE_COUNT 3

#endif // CONFIG_H_
