#include "includes.hpp"

void GameBoy::Init(const char* cartridge){
  Cartridge Insert(cartridge);
  Memory::Init();
}

void GameBoy::Run(){
  bool running = true;
  int counter = 0;
  while(running){
    print("PC: "); printhex(CPU::PC);
    print("Value: "); printhex(Memory::Address[CPU::PC]);
    int opcode = Memory::Address[CPU::PC];
    Instruction::fetch_decode(opcode);
    ++counter; if(counter == 40){running = false;}
  }
}

void GameBoy::Display(const char* tileset, const char* tilemap){
  window_test(tileset, tilemap);
}