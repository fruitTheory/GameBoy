#include "instructions.hpp"
#include "cpu.hpp"
#include "memory.hpp"
#include "utility.hpp"
#include <iostream>
#include <functional>

using namespace CPU;

std::unordered_map<int, void(*)()> opcode={
  {0xC3, JP_n16}, {0x3E, LD_A_n8}, {0xEA, LD_m16_A},
  {0xFE, LD_m16_A}, {0x38, JR_C_n8}, {0xCD, CALL_m16},
  {0x01, LD_BC_n16}, {0x21, LD_HL_n16},
};

// Call pushes address of instruction after 'call' to stack
// Then goes to the supplied address
void CALL_m16(){ // 0xCD
  Stack::Push((CPU::PC+2));
  CPU::PC = Memory::Get_Word();
}

// Relative Jump to address if Carry is set
// Note offsets need to be signed -128 to 127
void JR_C_n8(){ // 0x38
  int byte = Memory::Get_Byte();
  if(byte > 127){byte = Utils::convert_signed(byte);};
  if(Flag::Carry == true){CPU::PC += byte; }
}

// Subtract n8 value from A but throw away result
void CP_A_n8(){ // 0xFE
  int n8 = Memory::Get_Byte();
  int compare = Register::A - n8;
  if(compare == 0){Flag::Set(Flag::ZERO, true);}
  if(n8 > Register::A){Flag::Set(Flag::CARRY, true);}
  Flag::Set(Flag::SUBTRACT, true);
}

void LD_BC_n16(){ // 0x01
  int n16 = Memory::Get_Word();
  CPU::Register::B = n16 >> 8;
  CPU::Register::C = n16 & 0xFF00;
}

void LD_HL_n16(){ // 0x21
  int n16 = Memory::Get_Word();
  CPU::Register::H = n16 >> 8;
  CPU::Register::L = n16 & 0xFF00;
}

// Load A into an address
void LD_m16_A(){ // 0xEA
  int m16 = Memory::Get_Word();
  Memory::Write(m16, CPU::Register::A);
}

// Load byte into A
void LD_A_n8(){ // 0x3E
  int n8 = Memory::Get_Byte();
  CPU::Register::A = n8;
}

// Jump to address
void JP_n16(){ // 0xC3
  int n16 = Memory::Get_Word();
  CPU::PC = n16;
}



// // Add the value in r8 to A
// void ADD_A_r8(){ CPU::Register::A += r8; }
// // Add the byte pointed to by HL to A
// void ADD_A_HL(){ Register::A += Memory::Address[Register::H];}
// // Add the value n8 to A
// void ADD_A_n8(){ CPU::Register::A += n8; }
// // Add the value in r16 to HL
// void ADD_A_r16(){ CPU::Register::A += r16; }
// // Add the value in SP to HL
// void ADD_HL_SP(){ CPU::Register::H += Register::SP; }
// // Add the signed value e8 to SP
// void ADD_SP_e8(){ CPU::Register::SP += e8; }