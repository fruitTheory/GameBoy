#pragma once

#include <cstdint>
#include <vector>

// inline float shade[4]{0, 0.33f, 0.66f, 1};
inline uint8_t palette[4]{0, 84, 168, 255};
// enum col { BLACK, DARK_GREY, GREY, WHITE };

class PPU {
  public:

};

std::vector<int> get_tile();
std::vector<int> get_rom_values(int start_address, int amount_of_values);


/*
First we'll develop reading patterns into a buffer
8x8 patterns are defined by 16 bytes, and are grouped
in two's - each two groups of bytes are compared against
each other and the parallel bits combine to make a number
between 0-3, which determine which shade of grey it receieves
*/