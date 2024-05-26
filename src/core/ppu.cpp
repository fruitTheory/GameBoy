#include "ppu.hpp"
#include "cartridge.hpp"
#include "utility.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>

#define PIX_MULTIPLIER 3
using std::vector;
using std::array;
using TILE = std::vector<int>;
using TILEMAP = array<array<int, 256>, 256>;

// Get an 8x8 tiles pixel values (0-3) 64 bytes
vector<int> PPU::get_tile(int address){

  vector<int> tile;
  vector<int> rom_value = get_rom_values(address, 16);
  int shade{0};
  int iter{0};
  int arr_iter{0};
  // For loop to work with individual bits
  for(int a = 0; a < 8; ++a){
    for(int b = 7; b >= 0; b--){
      // Get current bit value, starting with most significant by using >> 7
      int current_b1 = rom_value[iter]>>b & 0b1;
      int current_b2 = rom_value[iter+1]>>b & 0b1;
      // Add current bits, assigning b2 as most significant << 1
      shade = current_b1 + (current_b2 << 1);
      tile.push_back(shade);

      ++arr_iter;
    }
  // Even Iterations, simulate 'every other'
  iter+=2;
  }
  return tile;
}

// Delete a 'row' from a vector tile collection, which is 32 vectors
void PPU::DeleteRow(vector<TILE> &tile_collection){
  for(int tile = 0; tile < 32; tile++){
    tile_collection.erase(tile_collection.begin());
  }
}

// Create and return a collection of tiles
vector<TILE> PPU::CreateTileCollection(){

  vector<int> tilemap_offsets = get_tilemap_offsets();
  vector<TILE> tile_collection;

  // Store tiles in a vector
  for(int offset : tilemap_offsets){
    vector<int> tile = get_tile(0x0 + offset);
    tile_collection.push_back(tile);
  }

  return tile_collection;

}

// Format tilemap into a mapped 256x256 array
void PPU::FormatTilemap(){

  // Collection of 1024 tiles
  vector<TILE> tile_collection = CreateTileCollection();

  array<array<int, 256>, 256> tilemap{0};

  int base_iter{0};

  while(tile_collection.size() != 0){ // Global condition

    for(int p_row = 0; p_row < 8; p_row++){ // pixel row

      for(int v_col = 0; v_col < 32; v_col++){ // vector column

        for(int p = 0; p < 8; p++){ // pixels

          tilemap[p_row+(8*base_iter)][p + (8*v_col)] = tile_collection[v_col][p +(8*p_row)];
        }
      }
    }
    PPU::DeleteRow(tile_collection);
    ++base_iter;
  }
  StoreTilemap(tilemap);
}

// Draw stored tilemap
void PPU::DrawTileMap(){

  int p_value{100}; // Pixel value/color
  int p_size = 1 * PIX_MULTIPLIER ; // Pixel size
  int p_alpha{255}; // Pixel Alpha

  TILEMAP tilemap = GetTilemap();

  for(int y = 0; y < 255; y++){
    for(int x = 0; x < 255; x++){
    
    // Pixels will accept the palette value
    switch(tilemap[y][x]){
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
    Color Ci = {p_value, p_value, p_value, p_alpha};
    DrawRectangle((x * p_size), (y * p_size), p_size, p_size, Ci);
    
    }
  }
}

// Utility way to get specific value from ROM
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

/*
Take byte from tilemap and multiply by 16(0x10)
to get the offset used to find necessary tile bytes in tileset
ex: 0x84 * 0x10 = 0x840
    0x85 * 0x10 = 0x850 depth in tileset memory

Take 16 bytes from memory represent a tile
*/
