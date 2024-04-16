#pragma once

#include <iostream>
#include <vector>
#include <stdint.h>

class Cartridge{

  private:
  
  static size_t measure_size(std::string file);
  uint8_t* load(std::string file, size_t fsize);

  public:

  Cartridge(std::string cartridge){
    size_t cart_size = measure_size(cartridge);
    std::cout << "Cartridge name: " << cartridge << std::endl;
    std::cout << "Cartridge size: " << cart_size << std::endl;
    Size = cart_size;
    Rom = load(cartridge, cart_size);
  };

  ~Cartridge(){
    delete[] Rom;
    Rom = nullptr;
  }
  
  uint8_t* Rom;
  size_t Size;

};