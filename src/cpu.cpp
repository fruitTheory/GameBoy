#include "cpu.hpp"
#include <iostream>


void temp_func(){ puts(" "); }

int cpu::registers::combine_registers(int high_bit, int low_bit){
  std::cout << "Hbit: " << high_bit << std::endl;
  high_bit <<= 8;
  int combined = high_bit + low_bit;
  std::cout << "Hbit: " << high_bit << std::endl;
  std::cout << "Comb: " << combined << std::endl;

  return combined;
}

