#include "ppu.hpp"
#include "cartridge.hpp"
#include "utility.hpp"
#include <iostream>
#include <vector>

using std::vector;

// Get an 8x8 tiles palette values (0-3)
vector<int> get_tile(){

  vector<int> tile;
  vector<int> rom_value = get_rom_values(0x15A0, 16);

  for(int a = 0; a < 8; ++a){
    static int iter = 0;
    for(int b = 7; b >= 0; b--){
      // Get current bit value, starting with most significant by using >> 7
      int current_b1 = rom_value[iter]>>b & 0b1;
      int current_b2 = rom_value[iter+1]>>b & 0b1;
      // Add current bits, assigning b2 as most significant << 1
      int shade = current_b1 + (current_b2 << 1);
      tile.push_back(shade);
    }
  // Even Iterations, simulate 'every other'
  iter+=2;
  }

  return tile;
}

// Utility like way to get specific value from ROM
vector<int> get_rom_values(int start_address, int amount_of_values){

  vector<int> bytes;
  for(int x = 0; x < amount_of_values; x++){
    bytes.push_back(Cartridge::Rom[start_address + x]);
  }
  return bytes;
}