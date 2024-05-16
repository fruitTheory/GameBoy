#pragma once

#include <vector>

// Single core cpu
namespace CPU {

  // Program counter
  extern int PC;
  inline void PC_increment(int value){CPU::PC += value;};

  // Flags - note these would be lower 8 bits of AF register
  struct Flag {

    inline static bool Zero; 
    inline static bool Subtract;
    inline static bool Half_Carry;
    inline static bool Carry;

    inline static void Set(bool &flag_type, bool value){flag_type = value;}
    inline static bool Get(bool &flag){return flag;};

  };

  // Stack
  class Stack
  {
  public:
    inline static std::vector<int> container;
  public:
    inline static void Push(int n16){container.push_back(n16);}
    inline static int Pop(){int value = container.back(); 
    container.pop_back(); return value; }
  };

    // Holds state of cpu
  struct Register {
    
    // 8-bit
    inline static int A;
    inline static int B;
    inline static int C;
    inline static int D;
    inline static int E;
    inline static int F;
    inline static int H;
    inline static int L;

    // 16-bit pointers
    inline static int PC;
    inline static int SP;

    static int Combine(int high_byte, int low_byte);
    static void Store_n16(int n16, int &reg_high, int &reg_low);

  };

  // Decode instructions  
  class control {

  };

}


/*
 CPU: 8-bit (Similar to the Z80 processor)
 Main RAM: 8K Byte
 Video RAM: 8K Byte
 Screen Size 2.6"
 Resolution: 160x144 (20x18 tiles)
 Max # of sprites: 40
 Max # sprites/line: 10
 Max sprite size: 8x16
 Min sprite size: 8x8
 Clock Speed: 4.194304 MHz
(4.295454 SGB, 4.194/8.388MHz GBC)
 Horiz Sync: 9198 KHz (9420 KHz for SGB)
 Vert Sync: 59.73 Hz (61.17 Hz for SGB)
 Sound: 4 channels with stereo sound
 Power: DC6V 0.7W (DC3V 0.7W for GB Pocket)

 1 machine cycle = 4 clock cycles
 GB CPU Speed NOP Instruction
Machine Cycles 1.05MHz 1 cycle
Clock Cycles 4.19MHz 4 Cycles
*/

/*
 * Registers:
 eight 8-bit registers A,B,C,D,E,F,H,L and two 16-
 bit registers SP & PC
 can be paired for 16 bit register AB CD etc.

*/

/*
 * Flags:
The Fleg Register consists of the following bits:
7 6 5 4 3 2 1 0
Z N H C 0 0 0 0

 Zero Flag (Z):
This bit is set when the result of a math operation
is zero or two values match when using the CP
instruction.

 Subtract Flag (N):
This bit is set if a subtraction was performed in the
last math instruction.

 Half Carry Flag (H):
This bit is set if a carry occurred from the lower
nibble in the last math operation.

 Carry Flag (C):
This bit is set if a carry occurred from the last
math operation or if register A is the smaller value
when executing the CP instruction.

*/

/*
 * Program Counter:
On power up, the GameBoy Program Counter is
initialized to $100 (100 hex) and the instruction found
at this location in ROM is executed.

The Program Counter from this point on is controlled,
indirectly, by the program instructions themselves that
were generated by the programmer of the ROM cart.

*/

/*
 * Stack:
add - CALL PUSH RST
rm - POP RET RETI

Set the Stack Pointer to $E000 using the
by using the command LD SP,$E000.

The Stack Pointer automatically decrements
before it puts something onto stack so its
acceptable to assign it a value one memory address
past the end of available RAM

The GameBoy stack pointer is initialized to $FFFE on
power up but a programmer should not rely on this
setting and rather should explicitly set its value.

*/
