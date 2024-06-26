#include "instructions.hpp"
#include "cpu.hpp"
#include "memory.hpp"
#include "utility.hpp"
#include <iostream>
#include <functional>

using namespace CPU;
using VoidPtr = void(*)();

std::unordered_map<int, VoidPtr> Instruction::execute={
  {0xC3, JP_n16}, {0x3E, LD_A_n8}, {0xEA, LD_m16_A},
  {0xFE, CP_A_n8}, {0x38, JR_C_n8}, {0xCD, CALL_m16},
  {0x01, LD_BC_n16}, {0x21, LD_HL_n16}, {0x22, LD_HLI_A},
  {0xFA, LD_A_n16},
};

void Instruction::fetch_decode(int opcode){
  if(Instruction::execute.contains(opcode)){
    Instruction::execute[opcode](); } 
  else{ throw std::runtime_error(
      std::format("Opcode (0x{:02X}) doesn't exist.", opcode)
    );
  }
}
// Call pushes address of instruction after 'call' to stack
// Then goes to the supplied address
void CALL_m16(){ // 0xCD
  Stack::Push((CPU::PC+3));
  CPU::PC = Memory::Get_Word();
}

// Relative Jump to address if Carry is set
// Note offsets need to be signed -128 to 127
void JR_C_n8(){ // 0x38
  int byte = Memory::Get_Byte();
  if(byte > 127){byte = Utils::convert_signed(byte);};
  if(Flag::Carry == true){CPU::PC_increment(byte);}
}

// Subtract n8 value from A but throw away result
void CP_A_n8(){ // 0xFE
  int n8 = Memory::Get_Byte();
  int compare = Register::A - n8;
  if(compare == 0){Flag::Set(Flag::Zero, true);}
  if(n8 > Register::A){Flag::Set(Flag::Carry, true);}
  Flag::Set(Flag::Subtract, true);
  CPU::PC_increment(2);
}

// Load 16 bit into BC combined register
void LD_BC_n16(){ // 0x01
  int n16 = Memory::Get_Word();
  CPU::Register::B = n16 >> 8;
  CPU::Register::C = n16 & 0x00FF;
  CPU::PC_increment(3);
}

// Load 16 bit into HL combined register
void LD_HL_n16(){ // 0x21
  int n16 = Memory::Get_Word();
  CPU::Register::H = n16 >> 8;
  CPU::Register::L = n16 & 0x00FF;
  CPU::PC_increment(3);
}

// Load A into address pointed to by HL and increment HL
void LD_HLI_A(){ // 0x22
  int n8 = Memory::Get_Byte();
  int HL = Register::Combine(Register::H, Register::L);
  Memory::Write(HL, n8); ++HL;
  Register::Store_n16(HL, Register::H, Register::L);
  CPU::PC_increment(1);
}

// Load A into an address
void LD_m16_A(){ // 0xEA
  int m16 = Memory::Get_Word();
  Memory::Write(m16, CPU::Register::A);
  CPU::PC_increment(3);
}

// Load word into A
void LD_A_n16(){ // 0xFA
  int n16 = Memory::Get_Byte();
  CPU::Register::A = n16;
  CPU::PC_increment(3);
}

// Load byte into A
void LD_A_n8(){ // 0x3E
  int n8 = Memory::Get_Byte();
  CPU::Register::A = n8;
  CPU::PC_increment(2);
}

// Jump to address
void JP_n16(){ // 0xC3
  int n16 = Memory::Get_Word();
  CPU::PC = n16;
}

