#include <iostream>
#include <array>
#include "ppu.hpp"
#include "cartridge.hpp"
#include "utility.hpp"

using std::array;

// Get an 8x8 tiles color values - atm one 8 pixel row
void get_tile(){

  uint8_t byte1 = Cartridge::Rom[0x20E];
  printf("%02X\n", byte1);

  uint8_t byte2 = Cartridge::Rom[0x20F];
  printf("%02X\n", byte2);

  array<int, 8> pixel_row;

  // Lsp to Msp - Combines parallel bit pairs to get color index
  for(int b = 7; b >= 0; b--){
    static int increment = 0;

    // Current bit value - b1 is least significant
    int current_b1 = byte1 & 0b1;
    int current_b2 = byte2 & 0b1;

    // Add current bits, assigning b2 as most significant
    int shade = current_b1 + (current_b2 << 1);
    pixel_row[increment] = shade;

    // Bit shift bytes
    byte1 >>= 1;
    byte2 >>= 1;
    increment++;
  }

  Utils::print_vector(pixel_row);

}