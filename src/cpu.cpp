#include "cpu.hpp"
#include <iostream>

using namespace CPU;

int CPU::PC = 0x100; // Initial pc address

void CPU::Stack::Push(int address){
  Stack::container.push_back(address);
}

void CPU::Stack::Pop(){
  Stack::container.pop_back();
}

void CPU::Flag::Set(Flag::type flag_type, bool value){
  switch (flag_type)
  {
  case 0:
    Flag::Zero = value;
    break;
  case 1:
    Flag::Subtract = value;
    break;
  case 2:
    Flag::Half_Carry = value;
    break;
  case 3:
    Flag::Carry = value;
    break;
  default:
    break;
  }
}

bool CPU::Flag::Get(Flag::type flag_type){
  switch (flag_type)
  {
  case 0:
    return Flag::Zero;
    break;
  case 1:
    return Flag::Subtract;
    break;
  case 2:
    return Flag::Half_Carry;
    break;
  case 3:
    return Flag::Carry;
    break;
  default:
    break;
  }
  throw std::runtime_error("Invalid Flag type");
}

int CPU::Register::Combine(int high_byte, int low_byte){
  int combined = (high_byte << 8) + low_byte;
  return combined;
}