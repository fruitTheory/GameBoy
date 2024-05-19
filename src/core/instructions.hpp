#pragma once

#include <unordered_map>

class Instruction{
  protected:
  static std::unordered_map<int, void(*)()> execute;

  public:
  static void fetch_decode(int opcode);
};

void LD_A_n8();
void LD_m16_A();
void LD_BC_n16();
void LD_HL_n16();
void LD_HLI_A();
void LD_A_n16();

void CP_A_n8();

void CALL_m16();
void CALL_cc_n16();

void JR_C_n8();
void JP_n16();

// FF44