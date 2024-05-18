#include "cartridge.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cstring>

using std::vector;
using std::istreambuf_iterator;

// Returns a vector of characters from input file
vector<uint8_t> Cartridge::load(const std::string file){

  std::ifstream cartridge(file, std::ios::in | std::ios::binary);
  vector<uint8_t> buffer((istreambuf_iterator<char>(cartridge)), 
  istreambuf_iterator<char>());
  cartridge.close();

  return buffer;
}