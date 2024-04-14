#include "cpu.hpp"
#include <iostream>


void temp_func(){ puts(" "); }

int cpu::registers::combine_registers(int high_byte, int low_byte){
  int combined = (high_byte << 8) + low_byte;
  return combined;
}