#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <iterator>
#include "config.hpp"
#include "utility.hpp"
#include "cartridge.hpp"

// Returns a buffer containing characters of input file
uint8_t* Cartridge::load(std::string file, size_t fsize){

  std::ifstream cartridge(file, std::ios::binary);
  uint8_t* buffer;

  if(cartridge){
      buffer = new uint8_t [fsize];
      cartridge.read(reinterpret_cast<char*>(buffer), fsize);
  }

  cartridge.close();

  return buffer;

}

// Return the size of an input file
size_t Cartridge::measure_size(std::string file){

  std::ifstream cartridge(file, std::ios::in | std::ios::binary);

  cartridge.seekg(0, std::ios::end);
  size_t filesize = static_cast<size_t>(cartridge.tellg());
  cartridge.seekg(0);
  cartridge.close();

  return filesize;
  
}