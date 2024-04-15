#include <iostream>
#include "utility.hpp"
#include "config.hpp"

// Only 16 bit max
void Utils::print_binary(int num){
  int byte = 7;
  if(num > 0xFF){byte = 15;}
  if(num > 0xFFFF){throw std::invalid_argument("16 bit number max");}
  for(int i = byte; i >= 0; i--){
      std::cout << ((num >> i) & 1);
  } std::cout << std::endl;
}
