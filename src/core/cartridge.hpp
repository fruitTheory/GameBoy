#pragma once

#include "memory.hpp"
#include <iostream>
#include <cstdint>
#include <vector>

using std::vector;

class Cartridge{

  private:
  vector<uint8_t> load(std::string file);

  public:
  Cartridge(const std::string cartridge){
    Rom = load(cartridge);
    std::cout << "Cartridge name: " << cartridge << std::endl;
    std::cout << "Cartridge size: " << Rom.size() << std::endl;
  };

  inline static vector<uint8_t> Rom;
  inline static vector<uint8_t> Tilemap; // Temporary Rom
  inline static vector<uint8_t> Tileset; // Temporary Rom
  void transfer_tilemap(){ Cartridge::Tilemap = Cartridge::Rom; };
  void transfer_tileset(){ Cartridge::Tileset = Cartridge::Rom; };
  
};
