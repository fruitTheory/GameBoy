#include "memory.hpp"
#include "cpu.hpp"
#include "cartridge.hpp"
#include "utility.hpp"
#include <iostream>
#include <format>
#include <vector>
#include <algorithm>

// Check if address is valid
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
// Specific read from memory address
int Memory::Read(int address){
  Memory::Check(address);
  int value = Memory::Address[address];
  std::cout << "value:" << value << std::endl;
  return value;
}
// Specific write to memory address
void Memory::Write(int address, int value){
  Memory::Check(address, value);
  Memory::Address[address] = value;
}

// Reading from memory using PC, returns n16
int Memory::Get_Word(){
  int low = Memory::Address[CPU::PC+1];
  int high = Memory::Address[CPU::PC+2];
  int n16 = CPU::Register::Combine(high, low);
  return n16;
}
// Reading from memory using PC, returns n8
int Memory::Get_Byte(){
  int n8 = Memory::Address[CPU::PC+1];
  return n8;
}

void Memory::CopyToMem(std::vector<uint8_t> vec, int address){
    if((vec.size() + address) > (ADDRESS_BUS + 1)){ 
      throw std::runtime_error("Copy beyond address bounds!");}
    std::copy(vec.begin(), vec.end(), Memory::Address.begin()+address);
}

void Memory::Init(){
  Memory::CopyToMem(Cartridge::Rom, 0x00);
}