#define NOBUILD_IMPLEMENTATION
#include "nobuild.h"

#define CC "g++"
#define CFLAG_DEBUG                                                            \
  "-Wall", "-Wextra", "-pedantic", "-std=c++20", "-ggdb", "-g", "-DDEBUG"
#define CFLAG_RELEASE                                                          \
  "-Wall", "-Wextra", "-pedantic", "-std=c++20", "-O3", "-s", "-DNDEBUG"
#define BUILD_DIR "build/"
#define SRC                                                                    \
  "src/Utils.cpp", "src/Assets.cpp", "src/Bird.cpp", "src/Raylib.cpp",         \
      "src/FlappyBird.cpp", "src/Main.cpp"
#define TARGET BUILD_DIR "FlappyBird"
#define LDFLAGS "-lraylib", "-lm"

int main(int argc, char **argv) {
  GO_REBUILD_URSELF(argc, argv);
  CMD("mkdir", "-p", BUILD_DIR);
  CMD(CC, CFLAG_DEBUG, SRC, "-o", TARGET, LDFLAGS);
  CMD(TARGET);
  return 0;
}
