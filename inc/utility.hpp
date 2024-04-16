#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
#include "config.hpp"

struct Utils{

  static void print_binary(int num);
  static void print_buffer(uint8_t* buffer, size_t size);

  // Print vector of any type
  template<typename T>
  static void print_vector(std::vector<T> vec){
    for(auto i : vec){
      printf("%02X ", vec[i]);
    } endline;
  }

};