#pragma once

#include <cstdint>
#include <vector>
#include "raylib.h"

// PPU design WIP

// inline float shade[4]{0, 0.33f, 0.66f, 1};

// enum col { BLACK, DARK_GREY, GREY, WHITE };

class PPU {
  private:
  static std::vector<int> get_tilemap_offsets();

  public:

  static inline uint8_t palette[4]{0, 84, 168, 255};
  static void DrawTile(std::vector<int> tile_pixels={0}, Vector2 pos={0});
  static void DrawTilemap();

  static std::vector<int> get_tile(int address);
  static std::vector<int> get_rom_values(int start_address, int amount_of_values);


};