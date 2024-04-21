#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cstdint>
#include "cpu.hpp"
#include "utility.hpp"
#include "cartridge.hpp"
#include "memory.hpp"


int main(int argc, char* argv[]){

  std::cout << "Hello C++" << std::endl;

  Cartridge Cartridge(argv[1]);
  
  // Utils::print_vector(Cartridge.Rom);

  Memory::Write(0x60, 100);
  Memory::Read(0x60);

  std::cout << "Goodbye C++" << std::endl;
  
  return EXIT_SUCCESS;

}


/*
 Interrupt Enable Register
 --------------------------- FFFF
 Internal RAM
 --------------------------- FF80
 Empty but unusable for I/O
 --------------------------- FF4C
 I/O ports
 --------------------------- FF00
 Empty but unusable for I/O
 --------------------------- FEA0
 Sprite Attrib Memory (OAM)
 --------------------------- FE00
 Echo of 8kB Internal RAM
 --------------------------- E000
 8kB Internal RAM
 --------------------------- C000
 8kB switchable RAM bank 
 --------------------------- A000
 8kB Video RAM 
 --------------------------- 8000 --
 16kB switchable ROM bank |
 --------------------------- 4000 |= 32kB Cartrigbe
 16kB ROM bank #0 |
 --------------------------- 0000 --


ROM Bank 0 (0000-3FFF): Contains the fixed code for the game, 
BIOS and the first 16KB of the game ROM

Switchable ROM Banks (4000-7FFF): Additional ROM banks that
can be swapped in and out of memory as needed

Video RAM (8000-9FFF): Memory used for storing graphics data, 
tile maps, and sprites

External RAM (A000-BFFF): Optional battery-backed 
memory for saving game data

Work RAM (C000-DFFF): General-purpose RAM used by the game
for variables, stack, and other temporary data

Echo RAM (E000-FDFF): Mirror of work RAM used for compatibility
with certain memory access patterns

Sprite Attribute Table (FE00-FE9F): Memory used to store
attributes for sprites (objects) on the screen

I/O Registers (FF00-FF7F): Memory-mapped I/O registers for controlling 
various system functions, including input, sound, and display.

High RAM (FF80-FFFE): Additional general-purpose RAM

Interrupt Enable Register (FFFF): Register for enabling and disabling interrupts

*/




