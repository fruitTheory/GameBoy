#include <iostream>
#include <cstdint>
#include "utility.hpp"
#include "config.hpp"

// print 16 bit max binary
void Utils::print_binary(int num){
  int byte = 7;
  if(num > 0xFF){byte = 15;}
  if(num > 0xFFFF){throw std::invalid_argument("16 bit number max");}
  for(int i = byte; i >= 0; i--){
      std::cout << ((num >> i) & 1);
  } endline;
}

// Print C style array
void Utils::print_buffer(uint8_t* buffer, size_t size){
  for(size_t i = 0; i < size; i++){
    printf("%02X ", buffer[i]);
  } endline;
}