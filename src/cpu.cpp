#include "cpu.hpp"
#include "config.hpp"
#include <iostream>


bool cpu::flag::Carry = false;
bool cpu::flag::Zero = false;

void cpu::do_me(cpu::flag input){ 
  std::cout << input.Carry << endline;}