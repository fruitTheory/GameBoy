#pragma once

#include <iostream>
#include <cstdint>

using std::vector;

class Cartridge{

  private:
  
  vector<uint8_t> load(std::string file);

  public:

  Cartridge(std::string cartridge){
    Rom = load(cartridge);
    std::cout << "Cartridge name: " << cartridge << std::endl;
    std::cout << "Cartridge size: " << Rom.size() << std::endl;
  };
  
  vector<uint8_t> Rom;
  
};
