#pragma once

#include <vector>

namespace GB{
class Window {
  public:
  static void Create();
  static void DrawPattern(std::vector<int> pattern={0});
};
}