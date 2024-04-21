#pragma once

void ADC_A_r8();
void ADC_A_HL();
void ADC_A_n8();
void ADC_A_r8();

void ADD_A_r8(int r8);
void ADD_A_HL();
void ADD_A_n8(int n8);
void ADD_HL_r16(int r16);
void ADD_HL_SP(int SP);
void ADD_SP_e8(int e8);

void DEC_r8();
void DEC_HL();
void DEC_r16();
void DEC_SP();
void DI();

void LD_r8_r8();
void LD_r8_n8();
void LD_r16_r16();
void LD_HL_r8();
void LD_HL_n8();
void LD_r8_HL();
void LD_r16_A();
void LD_n16_A();
void LD_A_r16();
void LD_A_n16();
void LD_HLI_A();
void LD_HLD_A();

void CALL_n16(int n16);
void CALL_cc_n16();