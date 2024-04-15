#pragma once

#include <iostream>
#include <vector>
#include <stdint.h>

class Cartridge{

  public:

  Cartridge(std::string cartridge){
    size_t cart_size = measure_size(cartridge);
    std::cout << "Cartridge size: " << cart_size << std::endl;
    Rom = load(cartridge, cart_size);
  };
  
  std::vector<uint8_t> Rom;

  static size_t measure_size(std::string file);
  std::vector<uint8_t> load(std::string file, size_t fsize);

};