#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>
#include "config.hpp"
#include "utility.hpp"
#include "cartridge.hpp"


std::vector<uint8_t> Cartridge::load(std::string file, size_t fsize){

  std::ifstream cartridge(file, std::ios::in | std::fstream::binary);
  std::vector<uint8_t> buffer(fsize, '0');

  cartridge.read(reinterpret_cast<char*>(buffer.data()), fsize);
  cartridge.close();

  return buffer;

}

size_t Cartridge::measure_size(std::string file){

  std::ifstream cartridge(file, std::ios::in | std::fstream::binary);

  cartridge.seekg(0, std::ios::end);
  size_t filesize = static_cast<size_t>(cartridge.tellg());
  cartridge.seekg(0, std::ios::beg);
  cartridge.close();

  return filesize;
  
}