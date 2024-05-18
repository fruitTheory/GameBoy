#include "cpu.hpp"
#include <iostream>

using namespace CPU;

int CPU::PC = 0x100; // Initial pc address

// Combine two bytes and return the value
int CPU::Register::Combine(int high_byte, int low_byte){
  int combined = (high_byte << 8) + low_byte;
  return combined;
}

// Store a 16 bit number into two registers high and low
void CPU::Register::Store_n16(int n16, int &reg_high, int &reg_low){
  int high_byte = n16 >> 8;
  int low_byte = n16 & 0x00FF;
  reg_high = high_byte;
  reg_low = low_byte;
}