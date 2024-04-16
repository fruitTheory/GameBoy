#pragma once

#include <iostream>
#include <cstdint>

class Cartridge{

  private:
  
  size_t measure_size(std::string file);
  uint8_t* load(std::string file, size_t fsize);

  public:

  Cartridge(std::string cartridge){
    Size = measure_size(cartridge);
    std::cout << "Cartridge name: " << cartridge << std::endl;
    std::cout << "Cartridge size: " << Size << std::endl;
    Rom = load(cartridge, Size);
  };

  ~Cartridge(){
    delete[] Rom;
    Rom = nullptr;
  }
  
  uint8_t* Rom;
  size_t Size;

};