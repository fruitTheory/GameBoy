#pragma once

#include "raylib.h"
#include <vector>

namespace GB{
class Window {
  public:
  static void Create();
};
}

void window_test(const char* tileset, const char* tilemap);