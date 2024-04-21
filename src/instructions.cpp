#include "instructions.hpp"
#include "cpu.hpp"
#include "memory.hpp"

using namespace CPU;


// Add the value in r8 to A
void ADD_A_r8(int r8){
  CPU::Register::A += r8;
}

// Add the byte pointed to by HL to A
void ADD_A_HL(){
  Register::A += Memory::Address[Register::H];
}

// Add the value n8 to A
void ADD_A_n8(int n8){
  CPU::Register::A += n8;
}

// Add the value in r16 to HL
void ADD_A_r16(int r16){
  CPU::Register::A += r16;
}

// Add the value in SP to HL
void ADD_HL_SP(int SP){
  CPU::Register::H += Register::SP;
}

// Add the signed value e8 to SP
void ADD_SP_e8(int e8){
  CPU::Register::SP += e8;
}

/* 
Call address n16. This pushes the address of the 
instruction after the CALL on the stack, such 
that RET can pop it later; then, it  executes
an implicit JP n16.
*/
void CALL_n16(int n16){
  // CPU::Stack::Push(current_address)
  // JP(n16)
}