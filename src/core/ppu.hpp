#pragma once

#include <vector>
#include <array>

using std::array;
using std::vector;
using TILE = std::vector<int>;
using TILEMAP = array<array<int, 256>, 256>;

class PPU {
  private:

  static void DeleteRow(vector<TILE> &tile_collection);
  static vector<int> get_tilemap_offsets();
  static vector<TILE> CreateTileCollection();
  static inline TILEMAP TileMap;

  public:

  static constexpr int palette[4]{0, 84, 168, 255};
  static vector<int> get_tile(int address);
  static vector<int> get_rom_values(int start_address, int amount_of_values);

  static void FormatTilemap();
  static void StoreTilemap(const TILEMAP &map){ TileMap = map; }
  static const TILEMAP &GetTilemap(){ return TileMap; }
  static void DrawTileMap();
  static int GetTilemapPixel(int mapX, int mapY);

  inline static int SCX; 
  inline static int SCY;

};