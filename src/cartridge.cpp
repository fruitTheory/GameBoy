#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include "cartridge.hpp"

#define byte char

using std::vector;
using std::istreambuf_iterator;

// Returns a vector of characters from input file
vector<uint8_t> Cartridge::load(std::string file){

  std::ifstream cartridge(file, std::ios::in | std::ios::binary);
  vector<uint8_t> buffer((istreambuf_iterator<byte>(cartridge)), 
  istreambuf_iterator<byte>());
  cartridge.close();

  return buffer;

}