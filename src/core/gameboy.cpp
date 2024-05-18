#include "includes.hpp"

void GameBoy::Init(const char* cartridge){
  Cartridge Insert(cartridge);
  Memory::Init();
}

void GameBoy::Run(){
  int opcode = Memory::Address[CPU::PC];
  Instruction::fetch_decode(0x01);
}

void GameBoy::Display(const char* tileset, const char* tilemap){
  window_test(tileset, tilemap);
}