#include "cpu.hpp"
#include <iostream>
#include <cstdint>

void func(){
  cpu::registers Register;
  Register.set_value(60);
  int val = Register.get_value();

  cpu::flag Flag;
  Flag.set_flag(true);
  int status = Flag.get_flag_status();

  std::cout << "val: " << val << std::endl;
  std::cout << "bool: " << status << std::endl;
  
}
