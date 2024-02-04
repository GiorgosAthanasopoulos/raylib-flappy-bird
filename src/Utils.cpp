#include <raylib.h>

#include "Utils.hpp"

Vector2 operator*=(Vector2 lhs, float rhs) {
  return {lhs.x * rhs, lhs.y * rhs};
}
