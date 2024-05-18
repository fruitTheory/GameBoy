#include "ppu.hpp"
#include "cartridge.hpp"
#include "utility.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>

#define PIX_MULTIPLIER 3
using std::vector;

// Get an 8x8 tiles pixel values (0-3) 64 bytes
vector<int> PPU::get_tile(int address){

  vector<int> tile;
  vector<int> rom_value = get_rom_values(address, 16);
  int shade = 0;
  int iter = 0;
  // For loop to work with individual bits
  for(int a = 0; a < 8; ++a){
    for(int b = 7; b >= 0; b--){
      // Get current bit value, starting with most significant by using >> 7
      int current_b1 = rom_value[iter]>>b & 0b1;
      int current_b2 = rom_value[iter+1]>>b & 0b1;
      // Add current bits, assigning b2 as most significant << 1
      shade = current_b1 + (current_b2 << 1);
      tile.push_back(shade);
    }
  // Even Iterations, simulate 'every other'
  iter+=2;
  }
  return tile;
}

// Utility like way to get specific value from ROM
vector<int> PPU::get_rom_values(int start_address, int amount_of_values){

  vector<int> bytes;
  for(int x = 0; x < amount_of_values; x++){
    bytes.push_back(Cartridge::Rom[start_address + x]);
  }
  return bytes;
}

// Returns the addresses of tiles used in tileset
vector<int> PPU::get_tilemap_offsets(){

  vector<int> tile_offsets;
  // For each byte in tilemap, get the calculated offset
  for(int byte : Cartridge::Tilemap){
    int offset = byte * 0x10; // decimal 16
    tile_offsets.push_back(offset);
  }
  return tile_offsets;
}

void PPU::DrawTilemap(){
  
  // int tilemap_size = Cartridge::Tilemap.size();
  vector<int> tilemap_offsets = PPU::get_tilemap_offsets();

  for(int offset : tilemap_offsets){

    static int inc_x, inc_y = 0;

    vector<int> tile = get_tile(0x0 + offset);
    int calc_x = ((inc_x*8)*PIX_MULTIPLIER);
    int calc_y = ((inc_y*8)*PIX_MULTIPLIER);
    
    if(inc_x == 31){ ++inc_y; }
    if(inc_x == 32){ calc_x = 0; inc_x = 0; }
    if(inc_y == 32){inc_y = 0;}

    Vector2 pos = {calc_x, calc_y};
    PPU::DrawTile(tile, pos);
    ++inc_x;
  }
}

// Draw pixels based on a tile
void PPU::DrawTile(vector<int>tile, Vector2 pos){

  int p_value = 100; // Pixel value/color
  int p_size = 1 * PIX_MULTIPLIER; // Pixel size
  int p_alpha = 255; // Pixel Alpha

  for(int pixel : tile){ // 64 pixels
    
    static int x, y = 0;
    static int inc_x, inc_y = 0;

    // Pixels will accept the palette value
    switch(pixel){
      case 0:
        p_value = PPU::palette[0];
        break;
      case 1:
        p_value = PPU::palette[1];
        break;
      case 2:
        p_value = PPU::palette[2];
        break;
      case 3:
        p_value = PPU::palette[3];
        break;
    }
    // Colour result
    Color Ci = {p_value, p_value, p_value, p_alpha};
    // Draw Pixel
    DrawRectangle(pos.x + (x), pos.y + (y), p_size, p_size, Ci);

    // If end of tile in X, increment Y and clear X
    if(inc_x == 7){ inc_x = 0; x = 0; ++inc_y; y += p_size;}
    else{ ++inc_x; x += p_size; }
    // Y is one step behind X hence 8 before needing clear Y
    if(inc_y == 8){ inc_y = 0; y = 0;}
  }

}

/*
Take byte from tilemap and multiply by 16(0x10)
to get the offset used to find necessary tile byte in tileset
ex: 0x84 * 0x10 = 0x840
    0x85 * 0x10 = 0x850 depth in tileset memory

Convert tilemap data into an array of 16-bit addresses 
that reference tiles in the tileset data
  vector addresses = {set of tile address};

Use these addresses to pull 16 bytes from to represent tile

Tile address - Map address(tilemap) 
20 tiles/bytes across 18 tiles/byte down
*/
