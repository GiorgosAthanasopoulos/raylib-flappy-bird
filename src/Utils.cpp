#include "Utils.hpp"

int AssertTextFitsInViewport(const char *text, int fontSize, Vector2 winSize) {
  int textW = MeasureText(text, fontSize);

  while (textW > winSize.x || fontSize > winSize.y) {
    fontSize--;
    textW = MeasureText(text, fontSize);
  }

  return fontSize;
}
