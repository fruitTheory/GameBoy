#include "cpu.hpp"
#include <iostream>


int cpu::registers::combine_registers(int high_byte, int low_byte){
  int combined = (high_byte << 8) + low_byte;
  return combined;
}

