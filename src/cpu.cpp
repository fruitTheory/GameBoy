#include "cpu.hpp"
#include "config.hpp"
#include <iostream>


bool cpu::flag::Zero = false;

void do_me(){ std::cout << cpu::flag::Zero << endline;}