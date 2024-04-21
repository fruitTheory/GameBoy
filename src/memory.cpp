#include "memory.hpp"
#include <iostream>
#include <format>

int Memory::Read(int address){
  Memory::Check(address);
  int value = Memory::Address[address];
  std::cout << "value:" << value << std::endl;
  return value;
}

void Memory::Write(int address, int value){
  Memory::Check(address, value);
  Memory::Address[address] = value;
}

void Memory::Check(int address, int value){
    if(address < 0 || address > ADDRESS_BUS){
    throw std::runtime_error(
    std::format("Address: '{}' out of 16-bit Range.", address)
    );
  } if(value < 0 || value > BYTE){
    throw std::runtime_error(
    std::format("Memory value: '{}' out of 8-bit Range.", value)
    );
  }
}