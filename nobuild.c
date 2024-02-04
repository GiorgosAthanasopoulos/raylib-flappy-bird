#define NOBUILD_IMPLEMENTATION
#include "nobuild.h"

int main(int argc, char **argv) {
  GO_REBUILD_URSELF(argc, argv);
  CMD("mkdir", "-p", "build");
  CMD("g++", "-Wall", "-Wextra", "-pedantic", "-std=c++20", "-ggdb", "-g",
      "-DDEBUG", "src/main.cpp", "-o", "build/FlappyBird", "-lraylib", "-lm");
  CMD("./build/FlappyBird");
  return 0;
}
